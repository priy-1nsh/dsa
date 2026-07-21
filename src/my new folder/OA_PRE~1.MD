# OA Battle Plan — Google (25th) → Cockroach Labs (27th) → DevRev (28th)

**Format for every block: Topic → Striver theory video (only if gap) → real OA question(s).**
Start: Tue 21 July, 7 PM. GS + DE Shaw parked until after the 28th.

---

## Standing rules (apply every day)

1. **Theory only where you have a gap.** Watch at 1.5–2x, code the template once, move to problems. Your base (easy + standard medium) means most videos are skims.
2. **Timebox: 30 min stuck → take hint → read editorial → close it → re-implement from scratch blind.** Re-implementing is the learning, not the reading.
3. **Google practice = plain text editor** (Notepad/blank file, no autocomplete). Their editor has zero assistance.
4. **CRL/DevRev practice = normal speed coding.** Both OAs reward fast, bug-free implementation; CRL gives partial marks — attempt ALL questions, never perfect one.
5. Keep a one-page "transitions notebook": every DP state definition + transition you learn, one line each. Revise it each morning (15 min).

---

## Topic ROI matrix

| Topic                       | Google              | CRL           | DevRev            | Your status                  |
| --------------------------- | ------------------- | ------------- | ----------------- | ---------------------------- |
| DP (grid/2D)                | ✅ dominant          | ✅             | ✅                 | ❌ weak — top priority        |
| DP (string/subseq)          | ✅                   | ✅ (LC 10 PYQ) | —                 | ❌ weak                       |
| 1D DP w/ state              | ✅ (PYQ)             | —             | ✅                 | ~L10 Striver                 |
| Sliding window              | ✅ (PYQ)             | —             | ✅ two pointers    | ❌ weak (med/hard)            |
| Tree DP / Trees             | ✅ (PYQ)             | ✅ BFS/DFS     | —                 | partial                      |
| Graphs (BFS/DFS/cycle/DSU)  | interview R2        | ✅             | ✅ **signature Q** | partial                      |
| Prefix sums / hashing       | ✅ (PYQ + interview) | ✅             | —                 | partial                      |
| Binary search on answer     | —                   | ✅ core        | —                 | partial                      |
| Intervals                   | —                   | ✅             | —                 | easy only                    |
| Greedy                      | ✅ (PYQ)             | ✅             | ✅                 | ❌ weak                       |
| Heaps / PQ                  | —                   | —             | ✅                 | ❌ weak                       |
| Bitmasking                  | —                   | —             | ✅                 | ❌ weak                       |
| Linked lists                | —                   | —             | ✅                 | ok                           |
| Tries, hard strings (KMP/Z) | —                   | —             | —                 | ❌ parked → GS/DE Shaw window |

---

## PHASE 1 — GOOGLE (tonight → OA on 25th)

Google OA reality: ~2 questions, both usually DP-flavored, time management decides. All 8 handbook PYQs mapped below.

### Tonight, Tue 21st (7 PM – ~11:30 PM) — Sliding Window

- **Theory (~1.5 h):** Striver Sliding Window & Two Pointer playlist, videos 1–4 (patterns, longest substring w/o repeat, max consecutive ones III, fruits into baskets).
- **Solve:**
  - 🎯 **Google PYQ #1 — Max count above threshold in window K** (fixed window, count > G)
  - LC 3 — Longest Substring Without Repeating Characters
  - LC 1004 — Max Consecutive Ones III
  - LC 424 — Longest Repeating Character Replacement (if energy left)
- 20 min: set up a plain-text file and code one of these in it, no IDE.

### DP Day 1: Grids + Subsequences (full day)

- **Morning — 2D/Grid DP (weak):** Striver DP 8–13 (Unique Paths → Min Path Sum → Triangle → Falling Path Sum).
  - LC 62, LC 64, LC 120, LC 931
- **Midday — 2D prefix sums** (Google interview R1 asked min-cost submatrix): short theory (any 2D prefix sum video/CP-Algorithms article) → LC 304 (Range Sum Query 2D) → LC 1074 (Submatrices Sum to Target).
- **Afternoon — Subsequence DP (weak):** Striver DP 14–20 speed-run (subset sum, partition equal, coin change, target sum).
  - LC 416, LC 494, LC 322
- **Evening — Google counting/state DP PYQs:**
  - LC 198 + 213 (house robber warmup, 20 min)
  - 🎯 **PYQ #3 — Max Happiness from Sweets** (1D DP, state = last consumed type: dp[i] tracking best ending with type A[i] via hashmap of best-per-type)
  - 🎯 **PYQ #7 — BusyTyping** (counting DP mod 1e9+7: f(i) = f(i-1) + f(i-2) over swappable adjacent pairs — Fibonacci-style; note constraint i and i+1 swap blocks i+1,i+2)

### Thu 23rd — DP Day 2: String DP + Tree DP + Prefix/Hash (full day)

- **Morning — String DP (weak):** Striver DP 25 (LCS), DP 33 (Edit Distance), DP 34 (Wildcard Matching).
  - LC 1143, LC 72, LC 44 ← *LC 44 doubles as direct prep for CRL's LC 10 PYQ*
- **Afternoon — Trees + Tree DP:** quick traversal refresher (Striver Trees playlist as needed) → LC 337 (House Robber III) → LC 124 (Max Path Sum).
  - 🎯 **PYQ #2 — Distributed Infrastructure (fortify tree nodes)**: attempt 45 min, then study solution — tree DP, dp[node][fortified/not], fortifying costs d × (number of fortified neighbors interaction); max-sum subset on tree. Re-implement blind.
- **Evening — Prefix sums + hashing:**
  - LC 525 (Contiguous Array — the exact +1/−1 prefix-hashmap trick)
  - 🎯 **PYQ #5 — Max Subarray after one deletion, equal >K and <K** (map to +1/−1, longest balanced after removing one subarray — prefix + hashmap)
  - 🎯 **PYQ #6 — Unit GCD Subsets**: read/derive solution (count elements equal to 1 vs >1; ordered-pair counting with mod pow). 30 min, understand the counting argument.

### Fri 24th — Google dress rehearsal (full day)

- **Morning — Greedy on strings (weak):**
  - 🎯 **PYQ #4 — Alphabet Ordering** (greedy partition into monotonic runs — verify against all 6 sample cases)
  - LC 763 (Partition Labels), LC 55 (Jump Game)
- **Midday — 90-min MOCK in plain text editor**, 2 unseen Google-style problems: LC 1937 (Maximum Points with Cost — 2D DP + prefix optimization) and LC 2140 (Solving Questions With Brainpower — 1D skip-DP). Simulate: no run button until done.
- **Afternoon:** redo every PYQ you didn't solve cleanly, from scratch. Revise transitions notebook.
- **Evening (light):** Striver Graphs — BFS (G-6) + DFS (G-7) videos only (seeds Google interview R2 + CRL/DevRev). Sleep early.

### Sat 25th — GOOGLE OA 🎯

- Morning: 15-min notebook revision + 2 already-solved warmups (LC 3, LC 64). Nothing new.
- **OA strategy:** scan both Qs first, start with the one you can finish; if a DP state isn't obvious in 10 min, write brute force for partial confidence, then optimize.
- **Post-OA evening → CRL pivot — Binary Search on Answer:** Striver BS-on-answer videos (Koko, Book Allocation, Aggressive Cows).
  - LC 875 (Koko), LC 410 (Split Array Largest Sum)
  - 🎯 **CRL PYQ — LC 981 Time Based Key-Value Store** (their own interview staple: lower_bound on timestamps)

---

## PHASE 2 — COCKROACH LABS (26th → OA on 27th)

CRL reality: HackerRank, 90 min, 3 Qs, medium–hard, **implementation-heavy, partial marks** → breadth beats depth.

### Sun 26th — CRL day (full day)

- **Morning — Intervals:** quick theory (Striver A2Z greedy: N-meetings / non-overlapping intervals) → LC 56 (Merge), LC 57 (Insert), LC 435 (Non-overlapping), LC 452 (Burst Balloons arrows).
- **Midday — Graphs BFS/DFS + shortest path:** Striver G-6/G-7 (done yesterday), + multi-source BFS concept → LC 200 (Islands), LC 994 (Rotten Oranges), LC 1091 (Shortest Path Binary Matrix).
- **Afternoon — String DP capstone:** 🎯 **CRL PYQ — LC 10 Regular Expression Matching** using the DP-34 wildcard template. Then 30-min grid-DP revision from notebook.
- **Evening — 90-min timed set of 3 implementation-heavy problems** (edge-case discipline): LC 54 (Spiral Matrix), LC 48 (Rotate Image), LC 6 (Zigzag Conversion ← *also a literal DevRev interview PYQ*). Goal: all 3 compile-and-pass, not elegance.

### Mon 27th — CRL OA 🎯

- Morning: revise BS-on-answer template + interval merging edge cases (empty, full overlap, single).
- **OA strategy:** attempt all 3; partial marks mean a working brute force on Q3 > a polished Q1. Budget ~25/30/35 min.
- **Post-OA evening → DevRev pivot — Graphs signature block:**
  - Striver G-11/12 (cycle undirected), G-19 (cycle directed DFS), G-22/23 (topo sort + Kahn's)
  - 🎯 LC 207 + LC 210 (Course Schedule I/II — *directed cycle detection, DevRev's recurring Q4*)
  - DSU: Striver G-46/47 → redo LC 547 (Provinces) with DSU
- **Night — Heaps/PQ (weak):** Striver heaps intro videos → LC 215 (Kth Largest), LC 347 (Top K Frequent), LC 621 (Task Scheduler — greedy + PQ, very DevRev-flavored).

---

## PHASE 3 — DEVREV (28th, OA day)

DevRev reality: CodeSignal, 90 min, 3–4 Qs easy→hard progression; **speed of clean implementation = the differentiator**; graphs/DP/greedy recur every season.

### Tue 28th — until OA time

- **Bitmasking (weak, ~1.5 h):** Striver A2Z bit manipulation basics → LC 78 (Subsets via bitmask), LC 136 (Single Number), LC 338 (Counting Bits).
- **Two pointers speed run (45 min):** LC 11 (Container With Most Water), LC 15 (3Sum).
- **Linked list refresh (30 min):** LC 206 (Reverse), LC 141 (Cycle), LC 21 (Merge Two).
- Warmup: re-solve LC 200 + one grid DP from memory.
- **OA strategy:** Q1–Q2 fast and clean (≤25 min combined), bank time for Q3/Q4 (graph/DP). Think edge cases BEFORE coding — debugging on CodeSignal under clock is brutal.

---

## Parked → GS/DE Shaw window (29th–31st)

Tries (Striver Trie playlist), hard strings (KMP/Z-function/rolling hash), remaining hard sliding window, plus whatever GS/DE Shaw handbooks demand. Send me those two batches on the 28th evening and I'll build Phase 4 the same way.

---

## PYQ checklist (tick as you clear them)

| #   | Question                       | Topic           | Company | Done |
| --- | ------------------------------ | --------------- | ------- | ---- |
| 1   | Window threshold count         | Sliding window  | Google  | ☐    |
| 2   | Fortify tree nodes             | Tree DP         | Google  | ☐    |
| 3   | Sweets happiness               | 1D DP + state   | Google  | ☐    |
| 4   | Alphabet ordering              | Greedy strings  | Google  | ☐    |
| 5   | Subarray deletion, equal >K/<K | Prefix + hash   | Google  | ☐    |
| 6   | Unit GCD subsets               | Counting + mod  | Google  | ☐    |
| 7   | BusyTyping                     | Counting DP     | Google  | ☐    |
| 8   | LC 981 Time-Based KV           | Binary search   | CRL     | ☐    |
| 9   | LC 10 Regex Matching           | 2D string DP    | CRL     | ☐    |
| 10  | LC 207/210 Course Schedule     | Cycle detection | DevRev  | ☐    |
| 11  | LC 6 Zigzag                    | Implementation  | DevRev  | ☐    |

**Supplementary pools when you outpace the plan:** LeetCode company tag pages (Google, Cockroach Labs — 19 tagged Qs: 4E/13M/2H), the Leader-board/OA-and-Interviews GitHub repo, and Codeforces Div 2 (1200–1700) for DevRev implementation speed.
