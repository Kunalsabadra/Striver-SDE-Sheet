#include <bits/stdc++.h> 

 void InsertSorted(stack<int>&st , int current){
	 if(st.empty() or current > st.top()){
		  st.push(current);
		  return;
	 }

     int top = st.top();
	 st.pop();
	 InsertSorted(st ,current);
	 st.push(top);

 }

void sortStack(stack<int> &st)
{
	if(st.empty()) return ;

    int top = st.top();
	st.pop();

	sortStack(st);

	InsertSorted(st , top);


}
