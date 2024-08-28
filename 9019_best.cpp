#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cout.tie(0), cin.tie(0);

  constexpr char FROM_A = 1, FROM_B = 0, NONE = -1;
  constexpr char OP[6] = "DDSLR";
  char op_pred[10000], visitor[10000];
  int pred[10000], neighbors[5];

  int T;
  cin >> T;
  while (T--){
    memset(visitor, NONE, 10000);
    int A, B;
    queue<int> q;
    
    cin >> A >> B;
    q.push(A);
    q.push(B);
    visitor[A] = FROM_A;
    visitor[B] = FROM_B;

    bool done = false;
    while (!done){
      int n = q.front();
      q.pop();
      char v = visitor[n];

      if (v == FROM_A){ // A에서 시작된 경우
        neighbors[1] = n < 5000 ? n << 1 : (n-5000) << 1; // D 계산
        neighbors[2] = n ? n-1 : 9999; // S 계산
        neighbors[3] = (n % 1000) * 10 + n / 1000; // L 계산
        neighbors[4] = (n%10) * 1000 + n / 10; // R 계산
      }
      else{ // B에서 시작된 경우
        neighbors[0] = n >> 1; // D 역계산 1 1000 -> 2000
        neighbors[1] = (n>>1) + 5000; // D 역계산 2 6000 -> 2000
        neighbors[2] = n < 9999 ? n+1 : 0; // S 역계산
        neighbors[3] = (n%10) * 1000 + n / 10; // L 역계산
        neighbors[4] = (n % 1000) * 10 + n / 1000; // R 역계산
      }
      
      // A의 경우 234 / B의 경우 1234 / NONE의 경우 제외 01234
      for (int i = (int)v; i < 5; ++i){ 
        if (i < 2 && (n & 1) && v == FROM_B) continue;
        int nn = neighbors[i];
        if (visitor[nn] == v) continue; // 같은 경로에서 한번 연산한 결과랑 겹칠 때
        else if (visitor[nn] == NONE){ // 새로운 경로일 때
          visitor[nn] = v;
          pred[nn] = n;
          op_pred[nn] = OP[i];
          q.push(nn);
        }
        else { // 경로가 합쳐졌을 때
          int a = n, b = nn; // 보기 편하도록 a와 b 변수명으로 둘 만듬
          // 만약 경로가 합쳐질 당시 B가 A를 만난경우 a와 b를 바꿔준다
          if (v == FROM_B) swap(a, b);  
          string s;
          
          for (; a!= A; a = pred[a]) // 입력한 A값이 될 때까지 a = 이전 계산값으로 감
            s.push_back(op_pred[a]); // 이전 계산값의 연산을 string에 추가함

          // rbegin과 rend를 통해 역방향 순회를 거쳐서 연산을 출력한다
          for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
            cout << *rit;
          //----- 여기까지가 A에서 중간까지의 명령 출력
          
          cout << OP[i]; // 이번에 실행한 연산 하나 출력

          // 입력한 B값이 될때까지 연산 출력
          for (; b != B; b = pred[b]) cout << op_pred[b];
          cout << '\n'; // 개행
          done = true; // while 탈출
          break; // while안 for 탈출
        }
      }
    }
  }
}