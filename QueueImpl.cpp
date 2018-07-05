template<typename T>
class CQueue{
	public:
		void push(const T& val){
			while(s2.size() > 0){
				s1.push(s2.top());
				s2.pop();
			}

			s1.push(val);
		}

		void pop(){
			while(s1.size() > 0){
				s2.push(s1.top());
				s1.pop();
			}

			s2.pop();
		}

		T& front(){
			while(s1.size() > 0){
				s2.push(s1.top());
				s1.pop();
			}

			return s2.top();
		}

		int size(){
			return s1.size() + s2.size();
		}

private:
	stack<T> s1;
	stack<T> s2;
}

void CQueueTest(){
	CQueue<int> q;
	for(int i=0; i<10; i++){
		q.push(i);
	}

	while(q.size() > 0){
		cout << q.front() << " ";
		q.pop();
	}
}
