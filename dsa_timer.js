#!/usr/bin/env node

// Usage:
//   node dsa_timer.js                        → 25 min, no problem name
//   node dsa_timer.js 20                     → 20 min
//   node dsa_timer.js 20 "Two Sum"           → 20 min, labelled

const c = {
  reset:  "\x1b[0m",
  bold:   "\x1b[1m",
  dim:    "\x1b[2m",
  red:    "\x1b[31m",
  green:  "\x1b[32m",
  yellow: "\x1b[33m",
  cyan:   "\x1b[36m",
};

const BAR_LEN    = 32;
const BELL       = "\x07";
const CLEAR_LINE = "\x1b[2K\r";

function fmt(sec) {
  const m = String(Math.floor(sec / 60)).padStart(2, "0");
  const s = String(sec % 60).padStart(2, "0");
  return `${m}:${s}`;
}

function clearScreen() {
  process.stdout.write("\x1b[2J\x1b[H");
}

function printHeader(minutes, problemName) {
  clearScreen();
  console.log(`\n${c.bold}${c.cyan}${"─".repeat(44)}${c.reset}`);
  console.log(`${c.bold}  🧠 DSA TIMER  —  ${minutes} minutes${c.reset}`);
  if (problemName) console.log(`${c.dim}  Problem: ${problemName}${c.reset}`);
  console.log(`${c.bold}${c.cyan}${"─".repeat(44)}${c.reset}\n`);
  console.log(`${c.dim}  [p] pause / resume        [q] quit${c.reset}\n`);
}

function printCheckpoint(msg) {
  process.stdout.write("\n");
  console.log(`${c.bold}${c.yellow}  ⚡ ${msg}${c.reset}\n`);
}

function printDone() {
  process.stdout.write("\n\n");
  console.log(`${c.bold}${c.red}${"─".repeat(44)}${c.reset}`);
  console.log(`${c.bold}${c.red}  ⏰  TIME'S UP${c.reset}`);
  console.log(`${c.bold}${c.red}${"─".repeat(44)}${c.reset}`);
  console.log(`\n${c.yellow}  → Look at the approach hint only.`);
  console.log(`  → Do NOT read the code yet.`);
  console.log(`  → Implement it yourself from scratch.${c.reset}\n`);
}

function main() {
  const args        = process.argv.slice(2);
  const minutes     = parseInt(args[0]) || 25;
  const problemName = args.slice(1).join(" ") || null;
  const total       = minutes * 60;

  const checkpoints = [
    { at: Math.floor(total / 2), msg: "Halfway. Still stuck? Think about what pattern fits.",       fired: false },
    { at: 5 * 60,                msg: "5 minutes left. No progress? Start forming your hint ask.",   fired: false },
  ].filter(cp => cp.at > 0 && cp.at < total);

  // ── keypress ────────────────────────────────────────────────
  if (!process.stdin.isTTY) {
    console.error(`${c.red}  Error: not a TTY — run directly in your terminal, not piped.${c.reset}\n`);
    process.exit(1);
  }

  process.stdin.setRawMode(true);
  process.stdin.resume();
  process.stdin.setEncoding("utf8");

  let paused   = false;
  let stopped  = false;
  let pausedAt = null;
  let startTime = Date.now();

  process.stdin.on("data", (key) => {
    if (key === "q" || key === "\u0003") { // q or Ctrl+C
      stopped = true;
    }
    if (key === "p") {
      if (!paused) {
        paused   = true;
        pausedAt = Date.now();
        process.stdout.write(CLEAR_LINE);
        process.stdout.write(`${c.yellow}  ⏸  PAUSED — press [p] to resume${c.reset}`);
      } else {
        startTime += Date.now() - pausedAt; // discount paused time
        paused    = false;
        pausedAt  = null;
      }
    }
  });

  // ── render ──────────────────────────────────────────────────
  printHeader(minutes, problemName);

  const interval = setInterval(() => {
    if (stopped) {
      clearInterval(interval);
      process.stdout.write("\n\n");
      console.log(`${c.dim}  Stopped. Good luck.${c.reset}\n`);
      process.stdin.setRawMode(false);
      process.exit(0);
    }

    if (paused) return;

    const elapsed   = Math.floor((Date.now() - startTime) / 1000);
    const remaining = Math.max(total - elapsed, 0);

    // checkpoints
    for (const cp of checkpoints) {
      if (!cp.fired && remaining <= cp.at) {
        cp.fired = true;
        printCheckpoint(cp.msg);
      }
    }

    // bar colour
    const pct      = Math.min(elapsed / total, 1);
    const filled   = Math.round(BAR_LEN * pct);
    const empty    = BAR_LEN - filled;
    const barColor = pct < 0.6 ? c.green : pct < 0.85 ? c.yellow : c.red;
    const barStr   = barColor + "█".repeat(filled) + c.dim + "░".repeat(empty) + c.reset;
    const timeColor = remaining <= 5 * 60 ? c.red : remaining <= total / 2 ? c.yellow : c.cyan;

    process.stdout.write(
      CLEAR_LINE +
      `  [${barStr}]  ${timeColor}${c.bold}${fmt(remaining)}${c.reset} remaining`
    );

    if (remaining === 0) {
      clearInterval(interval);
      process.stdout.write(BELL);
      printDone();
      process.stdin.setRawMode(false);
      process.exit(0);
    }
  }, 500);
}

main();
