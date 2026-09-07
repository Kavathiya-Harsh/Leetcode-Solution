// Last updated: 9/7/2026, 1:40:36 PM
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;

        return {kelvin,fahrenheit};
    }
};