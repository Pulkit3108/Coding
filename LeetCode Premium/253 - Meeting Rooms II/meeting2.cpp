// Problem Statement
// Given an array of meeting time intervals consisting of start and end times [[s1, e1], [s2, e2], ...] (si < ei), 
// find the minimum number of conference rooms required.

// Constraints:
// (0,8), (8,10) is not a conflict at 8.

// Examples:

// Example 1:
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: 2
// Explanation: 
// We need two meeting rooms:
// room1: (0,30)
// room2: (5,10), (15,20)

// Example 2:
// Input: intervals = [(2,7)]
// Output: 1
// Explanation: Only need one meeting room.

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
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= endTimes.top()) {
                endTimes.pop();
            }
            endTimes.push(intervals[i].end);
        }

        return endTimes.size();
    }
};
