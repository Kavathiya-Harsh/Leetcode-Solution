// Last updated: 9/7/2026, 1:40:17 PM
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};