// Last updated: 6/2/2026, 9:45:40 AM
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;

        return {kelvin,fahrenheit};
    }
};