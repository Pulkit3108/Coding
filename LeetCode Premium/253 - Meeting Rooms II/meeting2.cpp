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
     * @return: the minimum number of conference rooms required
     */

    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2) {
            return i1.start < i2.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0].end);

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i].start >= minHeap.top()) {
                minHeap.pop();
            }

            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    } 
};
