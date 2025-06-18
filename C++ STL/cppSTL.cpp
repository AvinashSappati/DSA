#include<bits\stdc++.h>
using namespace std;

//Pairs
void Pair()
{
      pair<int,int> x = {1,2} ;// similar to {{1,2}}
      cout << x.first << endl << x.second ;

      pair<int,pair<float,float>> y = {1,{2.1,2.2}};
      cout << y.first << endl << y.second.first << endl << y.second.second << endl;

      pair<int,int> arr[] = {{1,2},{2,5},{5,1}};
      cout << arr[1].second;    
}

//Vectors
void Vector()
{
      vector<int> v; // {}
      v.push_back(1);//{1}
      v.emplace_back(2);//{1,2}

      //cout << v[1] ;

      vector<pair<int,int>> v1; //{{}}
      v1.push_back({1,2});//{{1,2}}
      v1.emplace_back(1,2);//{{1,2}}
      //cout << v1[0].second ;

      vector<int> v2(5,100);//{100,100,100,100,100}
      //cout << v2[1];
      vector<int> v3(5);//{0,0,0,0,0}
      vector<int> v4(5,20);//{20,20,20,20,20}
      vector<int> v5(v4);

      //ITERATORS-It stores address (like a pointer in C)
      vector<int>::iterator it = v.begin(); // v = {1,2}
      //cout << *it;
      // Points to the address right after vector v , it-- is the address of last element
      vector<int>::iterator it1 = v.end(); 

      //NEVER USED (Reverse of begin and ends , increment points from back to begin)
      //vector<int>::iterator it = v.rend(); 
      //vector<int>::iterator it = v.rbegin();

      //cout << v[0] << " " << v.at(0) << " ";
      //cout << v.back() << " ";


      vector<int> vec = {1,2,3,4,5};
      for(vector<int>::iterator it3 = vec.begin();it3!=vec.end();it3++)
      {
            //cout << *(it3) << " ";
      }

      for(auto it = vec.begin();it!=vec.end();it++)
      {
            //cout << *(it) << " ";
      }
      //BETTER
      for(auto it : vec)
      {
            // cout << it << " ";
      }

      //ERASE FUNCTION
      //{10,20,12,23}
      vector<int> vec1 = {10,20,12,23};
      vec1.erase(vec1.begin()+1);//{10,12,23}
      vec1.erase(vec1.begin(),vec1.begin()+1);//{12,23}
      for(auto it : vec1)
      {
            //cout << it << " ";
      }

      //INSERT FUNCTION
      vector<int> vec2(2,100);//{100,100}
      vec2.insert(vec2.begin(),300);//{300,100,100}
      vec2.insert(vec2.begin()+2,2,10);//{300,100,10,10,100}

      //copying a whole vector and insert!
      vector<int> copy(2,50);//{50,50}
      vec2.insert(vec2.begin(),copy.begin(),copy.end());//{50,50,300,100,10,10,100}

      //cout << vec2.size() << endl;
      for(auto it : vec2)
      {
            cout << it << " ";
      }
      //vec2 = {50,50,300,100,10,10,100}
      vec2.pop_back();//removes last element

      //vec1 -> {12,23}
      //vec2 -> {50,50,300,100,10,10,100}
      vec1.swap(vec2); 
      vec1.clear();//{}

      // cout << v.empty(); //returns 0 or 1.
}

//List
void List()
{
      list<int> ls;
      ls.push_back(2); //{2}
      ls.emplace_back(4); //{2,4}

      //vector insert is taking  constraints more.So,push_front is preferred over it !
      ls.push_front(5); //{5,2,4}
      ls.emplace_front(); // //{0,5,2,4}

      for(auto it : ls)
      {
            //cout << it << " ";
      }

      //rest functions same as vector
      //begin,end,rbegin,rend,clear,insert,size,swap
}

//Deque
void Deque()
{
      deque<int> dq;//{}
      dq.push_back(1);//{1}
      dq.emplace_back(2);//{1,2}
      dq.push_front(3);//{3,1,2}
      dq.emplace_front(4);//{4,3,1,2}

      dq.pop_back();//{4,3,1}
      dq.pop_front();//{3,1}

      dq.back();//returns 1
      dq.front();//returns 3

      //rest functions same as vector
      //begin,end,rbegin,rend,clear,insert,size,swap
}

//Stack - LIFO { --> }
void Stack()
{
      //only three functions in stack for generally !
      //all are 0(1) notation only !
      stack<int> st;//{}
      st.push(1);//{1}
      st.push(2);//{2,1}
      st.emplace(3);//{3,2,1}
      st.top();// returns 3
      st.pop();//{2,1}
      st.size();// returns 2
      st.empty();//{}

      stack<int> st1,st2;
      st1.swap(st2);
}

//Queue - FIFO { <-- }
void Queue()
{
      queue<int> q;//{}
      q.push(1);//{1}
      q.push(2);//{1,2}
      q.emplace(3);//{1,2,3}

      q.back() += 5; //{1,2,8}
      q.pop();//{1,2} - removed 8
      q.front(); // returns 1

      //size swap empty same as stack
}

//Priority Queue
void PQ()
{
      /*
      Push -> log(n)
      top -> O(1)
      pop -> log(n)
      */
      //Max heap
      //if we use below declaration , then characters,numbers,strings are lexicographically arranged !
      // Tree-Data Structure
      priority_queue<int> pq;

      pq.push(5); //{5}
      pq.push(2); //{5,2}
      pq.push(8);//{8,5,2}
      pq.emplace(10);//{10,8,5,2}
      pq.top();//{8,5,2}

      //size swap empty function same as others

      //Minimum Heap(reverse-priority )
      priority_queue<int,vector<int>,greater<int>> pq1;
      pq1.push(5);//{5}
      pq1.push(3);//{3,5}
      pq1.push(8);//{3,5,8}
      pq1.emplace(10);//{3,5,8,10}

      cout << pq1.top(); // returns 3

}

//Set (unique,sorted) ( --> )
void Set()
{
      set<int> st;//{}
      st.insert(1);//{1}
      st.insert(2);//{1,2}
      st.emplace(2);//{1,2} ,number not inserted
      st.insert(3);//{1,2,3}
      

}
int main()
{
    //Pair();
    //Vector();
    //List();
    //Deque();
    //Stack();
    //PQ();//priority_queue
    Set();
    return 0;  
}