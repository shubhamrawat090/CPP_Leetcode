class Solution {
public:
    double angleClock(int hour, int minutes) {
        double oneMinAngle = 6;
        double oneHourAngle = 30;
        double minutesAngle = oneMinAngle * minutes;
        double hoursOffset = (minutes / 60.0);
        double hoursAngle = (hour + hoursOffset) * oneHourAngle;
        double finalAngle = abs(hoursAngle - minutesAngle);
        double complement = abs(360 - finalAngle);
        return complement < finalAngle ? complement : finalAngle;
    }
};