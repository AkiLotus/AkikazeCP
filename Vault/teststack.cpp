#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> Operator;
	stack<long long> Value;
	long long t;
	cin >> t;
	while (t-- > 0) {
		string math;
		cin >> math;
		math = "(" + math + ")";
		for (long long i=0; i<math.size(); i++) {
			if (math[i] >= '0' && math[i] <= '9') {
				long long pos = i;
				string num; num += math[pos];
				while (pos+1 < math.size() && math[pos+1] >= '0' && math[pos+1] <= '9') {
					pos++;
					num += math[pos];
				}
				i = pos;
				long long llnum = stoll(num);
				Value.push(llnum);
			}
			else if (math[i] == '(') Operator.push(math[i]);
			else if (math[i] == '+' || math[i] == '-' || math[i] == '*') {
				while (!Operator.empty() && ((Operator.top() == '+' || Operator.top() == '-' || Operator.top() == '*')
				|| (math[i] == '*' && (Operator.top() == '+' || Operator.top() == '-')))) {
					char ope = Operator.top(); Operator.pop();
					long long param1 = Value.top(); Value.pop();
					long long param2 = Value.top(); Value.pop();
					long long res;
					if (ope == '+') res = param1 + param2;
					else if (ope == '-') res = param1 - param2;
					else if (ope == '*') res = param1 * param2;
					Value.push(res);
				}
				Operator.push(math[i]);
			}
			else if (math[i] == ')') {
				while (!Operator.empty() && Operator.top() != '(') {
					char ope = Operator.top(); Operator.pop();
					long long param1 = Value.top(); Value.pop();
					long long param2 = Value.top(); Value.pop();
					long long res;
					if (ope == '+') res = param1 + param2;
					else if (ope == '-') res = param2 - param1;
					else if (ope == '*') res = param1 * param2;
					Value.push(res);
				}
				Operator.pop();
			}
		}
		cout << Value.top() << endl;
	}
	return 0;
}
