// class Solution {
// public:
//     long long taskSchedulerII(vector<int>& tasks, int space) {
//         // 1: 1
//         // 2: 2
//         // 3: 
//         // 4: 
//         // 5: 1
//         // 6: 2
//         // 7: 3
//         // 8: 
//         // 9: 1
//         unordered_map<int, int> hashmap;
//         long long day = 0;
//         int i = 0;
//         while(i<tasks.size()){
//             day++;
//             if(hashmap.find(tasks[i])!= hashmap.end()){
//                 if(hashmap[tasks[i]] <= day){
//                     hashmap[tasks[i]] = day + space + 1;
//                     i++;
//                 }
//                 else continue;
//             }
//             else
//             {
//                 hashmap[tasks[i]] = day + space + 1;
//                 i++;
//             }
//         }
//         return day;
//     }
// };

// 1: 5 (4)
// 2: 8 (5)
// 3: 
// 4: 
// 5: 8(11)
// 6: 5 ()

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        // 1: 1
        // 2: 2
        // 3: 
        // 4: 
        // 5: 1
        // 6: 2
        // 7: 3
        // 8: 
        // 9: 1
       unordered_map<long long, long long> hashmap; // Tracks the next available day for each task
        long long day = 0;

        for (auto task : tasks) {
            // Increment day
            day++;
            
            // If the task is within the cooldown period, jump to its next available day
            if (hashmap.find(task) != hashmap.end() && hashmap[task] >= day) {
                day = hashmap[task];
            }
            
            // Update the next available day for the task
            hashmap[task] = day + space + 1;
        }

        return day;
    }
};
