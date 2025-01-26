//Approach

/*
For this problem, we can find the number of car fleets that will arrive at the target. 
A car fleet consists of one or more cars that travel together at the same speed, meaning no car in the fleet can overtake another once they have formed a fleet.
Steps to solve the problem:
Pairing Cars:

We first create a custom Car class to store the position and speed of each car.
We then construct a list of Car objects from the given position and speed arrays.

Sorting:

To determine fleet formation, cars should be sorted by their starting positions in ascending order.
This allows us to process the cars from the nearest to the farthest from the target.

Fleet Calculation:

We traverse the sorted cars and compute the time required for each car to reach the target using the formula:

time = (target−position)/speed

Using a stack, we keep track of the fleet times:
If the current car takes longer to reach the target than the car in front of it (on top of the stack), it forms a new fleet.
Otherwise, it will merge with the fleet in front of it (i.e., we pop from the stack).

Result:

The final size of the stack represents the number of car fleets reaching the target.

Time Complexity = O(nlogn)
*/




class Solution {
    class Car{
        public:
          int pos,speed;
          Car(int p,int s): pos(p),speed(s){};
    };
    static bool myComp(Car &a, Car &b){
        return a.pos < b.pos;
    }
 public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<Car>cars;
       for(int i=0;i<position.size();i++)
       {
          Car car(position[i],speed[i]);
          cars.push_back(car);
       } 
       sort(cars.begin(),cars.end(),myComp);
       stack<float>st;
       for(auto car:cars)
       {
          float time = (target-car.pos)/((float)car.speed);
          while(!st.empty() && time >= st.top())
          {
            st.pop();
          }
          st.push(time);
       }
       return st.size();
    }
};