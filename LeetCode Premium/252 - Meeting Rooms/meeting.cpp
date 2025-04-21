// Problem Statement
// Given an array of meeting time intervals consisting of start and end times [(s1, e1), (s2, e2), ...] (si < ei), 
// determine if a person could attend all meetings.

// Constraints:
// 0 ≤ intervals.length ≤ 10^4
// intervals[i].length == 2
// 0 ≤ starti < endi ≤ 10^6
// [(0,8), (8,10)] is not a conflict at 8.

// Examples:

// Example 1:
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: false
// Explanation: (0,30), (5,10) and (0,30), (15,20) will conflict.

// Example 2:
// Input: intervals = [(5,8),(9,15)]
// Output: true
// Explanation: Two times will not conflict.

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
    bool canAttendMeetings(vector<Interval> &intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};
