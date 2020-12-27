class Solution {
public:
    double angleClock(int hour, int minutes) {
        double am_h = 0.5; // angle per minute of the hour hand
        double ah_0 = hour * 30;
        double am = minutes * 6; // angle of the minute hand w.r.t 0
        double ah = ah_0 + minutes * am_h; // // angle of the hour hand w.r.t 0
        double res = abs(am - ah);
        if (res > 180) res = 360 - res;
        return res;
    }
};