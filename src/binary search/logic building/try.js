/**
 * @param {string} time
 * @return {number}
 */
var countTime = function(time) {
    let countHours = 0;
    let countMinutes = 0;
    const hours = time.substring(0, 2);
    const minutes = time.substring(3, 5);

    // count hours
    if (hours === "??") countHours = 24;
    else if (hours[0] === '?') {
        if (['0','1','2','3'].includes(hours[1])) countHours = 3;
        else countHours = 2;
    }
    else if (hours[1] === '?') {
        if (hours[0] === '0' || hours[0] === '1') countHours = 10;
        else if (hours[0] === '2') countHours = 4;
        else countHours = 0;
    }
    else countHours = 1;

    // count minutes
    if (minutes === "??") countMinutes = 60;
    else if (minutes[0] === '?') countMinutes = 6;
    else if (minutes[1] === '?') countMinutes = 10;
    else countMinutes = 1;

    return countHours * countMinutes;
};