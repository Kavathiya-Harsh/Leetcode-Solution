// Last updated: 6/29/2026, 8:46:34 AM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Step 1: convert hour to 12 format
        hour = hour % 12;

        // Step 2: calculate angles
        double minuteAngle = 6 * minutes;
        double hourAngle = 30 * hour + 0.5 * minutes;

        // Step 3: find difference
        double angle = abs(hourAngle - minuteAngle);

        // Step 4: return smaller angle
        return min(angle, 360 - angle);
    }
};