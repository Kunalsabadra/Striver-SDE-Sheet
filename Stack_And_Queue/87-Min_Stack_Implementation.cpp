#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	
	public:
			stack<pair<int, int>> st;
		
		minStack() 
		{ }
	
		
		void push(int num)
		{ 
			int mini;
			if(st.empty()) mini = num;
			else mini = std::min(st.top().second , num);

			st.push({num , mini});
			
		}
		
		int pop()
		{
			if(st.empty()) return -1;

			int ans =  st.top().first;
			st.pop();
			return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{     
				if(st.empty()) return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{  
				if(st.empty()) return -1;
			return st.top().second;
		}
};
