// Last updated: 6/11/2026, 8:11:55 AM
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};