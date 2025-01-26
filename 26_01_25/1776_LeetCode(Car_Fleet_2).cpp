//Approach

/*
For this problem, we need to determine the time at which each car will collide with the car in front of it. 
If a car never collides with another car, the answer for that car should be -1.
The approach follows a greedy method using a stack to process the cars from right to left.

Steps to solve the problem:

We create an answer vector initialized with -1 to store collision times.
A stack is used to keep track of indices of cars that might collide.

We process the cars from the last to the first because the last car will never collide with another car.

If the current car's speed is greater than or equal to the speed of the car in front of it (top of stack), it will never collide, so we remove the slower car from the stack.

If a car in front is moving slower, we calculate the potential collision time using the formula:
   collison_time = (next_position-curr_position)/(curr_speed - next_speed)
If the car in front already has a collision time and our calculated collision time exceeds it, 
we ignore this car, since it will already have collided before the current car reaches it. 

If the calculated collision time is valid (i.e., less than or equal to the next car's collision time), we store it in the answer vector.

After processing a car, push its index onto the stack for future comparisons.

Time Complexity = O(n)
*/



class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>answer(cars.size(),-1);
        stack<int>st;
        for(int i=cars.size()-1;i>=0;i--)
        {
          while(!st.empty() && cars[st.top()][1] >= cars[i][1])
          {
            st.pop();
          }
          while(!st.empty())
          {
            double colTime = (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
            if(answer[st.top()] == -1 || colTime <= answer[st.top()])
            {
                answer[i] = colTime;
                break;
            }
            st.pop();
          }
          st.push(i);
        }
        return answer;
    }
};