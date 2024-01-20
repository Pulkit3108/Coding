/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    static bool compareInterval(const Interval &i1,const Interval &i2){
        return i1.start < i2.start;
    }
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.size()==0)
            return true;
        sort(intervals.begin(),intervals.end(),compareInterval);
        Interval previousInterval=intervals[0];
        for(int i=1;i<intervals.size();++i){
            Interval currentInterval=intervals[i];
            if(currentInterval.start<previousInterval.end)
                return false;
            previousInterval=currentInterval;
        }
        return true;
    }
};
