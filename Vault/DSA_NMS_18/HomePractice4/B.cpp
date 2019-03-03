#include <iostream>
#include <stack>
using namespace std;
 
long long s_ll(string z) {
	long long num = 0;
	for (int i=0; i<z.size(); i++) {
		num *= 10;
		num += z[i] - '0';
	}
	return num;
}
 
int main() {
	stack<char> Operator;
	stack<long long> Value;
	long long t;
	cin >> t;
	while (t-- > 0) {
		string math;
		cin >> math;
		for (long long i=0; i<math.size(); i++) {
			if (math[i] >= '0' && math[i] <= '9') {
				long long pos = i;
				string num; num += math[pos];
				while (pos+1 < math.size() && math[pos+1] >= '0' && math[pos+1] <= '9') {
					pos++;
					num += math[pos];
				}
				i = pos;
				long long llnum = s_ll(num);
				Value.push(llnum);
				//cout << "new top value = " << Value.top() << endl;
			}
			else if (math[i] == '(') Operator.push(math[i]);
			else if (math[i] == '+' || math[i] == '-' || math[i] == '*' || math[i] == '/') {
				while (!Operator.empty() && ((math[i] == '+' || math[i] == '-') && (Operator.top() == '+' || Operator.top() == '-' || Operator.top() == '*' || Operator.top() == '/')
				|| ((math[i] == '*' || math[i] == '/') && (Operator.top() == '*' || Operator.top() == '/')))) {
					char ope = Operator.top(); Operator.pop();
					long long param1 = Value.top(); Value.pop();
					long long param2 = Value.top(); Value.pop();
					long long res;
					if (ope == '+') res = param2 + param1;
					else if (ope == '-') res = param2 - param1;
					else if (ope == '*') res = param2 * param1;
					else if (ope == '/') res = param2 / param1;
					Value.push(res);
					//cout << "new top value = " << Value.top() << endl;
				}
				Operator.push(math[i]);
			}
			else if (math[i] == ')') {
				while (!Operator.empty() && Operator.top() != '(') {
					char ope = Operator.top(); Operator.pop();
					long long param1 = Value.top(); Value.pop();
					long long param2 = Value.top(); Value.pop();
					long long res;
					if (ope == '+') res = param2 + param1;
					else if (ope == '-') res = param2 - param1;
					else if (ope == '*') res = param2 * param1;
					else if (ope == '/') res = param2 / param1;
					Value.push(res);
					//cout << "new top value = " << Value.top() << endl;
				}
				Operator.pop();
			}
		}
		while (!Operator.empty()) {
			char ope = Operator.top(); Operator.pop();
			long long param1 = Value.top(); Value.pop();
			long long param2 = Value.top(); Value.pop();
			long long res;
			if (ope == '+') res = param2 + param1;
			else if (ope == '-') res = param2 - param1;
			else if (ope == '*') res = param2 * param1;
			else if (ope == '/') res = param2 / param1;
			Value.push(res);
			//cout << "new top value = " << Value.top() << endl;
	
		}
		cout << Value.top() << endl;
	}
	return 0;
}