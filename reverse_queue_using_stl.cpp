//reverse a queue using stl

queue<long long int> rev(queue<long long int> q)
{
    // add code here.
    stack<long long int> st;
    int n=q.size();
    for(int i=0;i<n;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        
        q.push(st.top());
        st.pop();
    }
    return q;
}