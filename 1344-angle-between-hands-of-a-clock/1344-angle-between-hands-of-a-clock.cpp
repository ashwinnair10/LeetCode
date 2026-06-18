class Solution {
public:
    double angleClock(int hour, int minutes) {
        return abs(30*hour-5.5*minutes)>180?360-abs(30*hour-5.5*minutes):abs(30*hour-5.5*minutes);
    }
};