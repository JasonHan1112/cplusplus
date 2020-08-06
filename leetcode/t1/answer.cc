#include <vector>
#include <iostream>
using namespace std;


class Answer {
public:
    vector<int> ret = vector<int>();

    vector<int> twoSum(vector<int>& nums, int target);
};


vector<int> Answer::twoSum(vector<int>& nums, int target) {        
    cout << "hello world" << endl;   
    cout << "nums.size:" << nums.size() << endl;    
   
    for(int i = 0; i < nums.size(); i++)
    {
        int tmp = target - nums[i];
        for(int j = 0; j < nums.size(); j++)
        {
            if(j == i)//can't repeat
            {
                cout << "continue" << endl;
                continue;
            }
            else if(tmp == nums[j])
            {
               
                ret.push_back(i);
                ret.push_back(j);
                cout << "find you" << endl;
                return ret;
            }
            else
            {
                cout << "haven't find" << endl;
            }
       }
    }
    return ret;
}

int main(void)
{
    cout << "hello world" << endl;
    vector<int> ret; 
    vector<int> nums {0,1,2,3,4,5,6,7,8,9,10};
    Answer a;
    int target = 20;
    ret = a.twoSum(nums, target);
    cout << "target: " << target << endl;
    cout << "ret.size: " << ret.size() << endl;
    if(ret.size() == 2)
    {
        cout << "ret0: " << ret.at(0) << endl;
        cout << "ret1: " << ret.at(1) << endl;
    }
    return 0;
}
