#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer;

    //1. 인자 sort
    sort(tickets.begin(), tickets.end(), greater<vector<string> >());

    // 각 공항에서 출발하는 항공권의 집합 설정
    unordered_map<string, vector<string> > routes;

    for(int i = 0; i < tickets.size(); i++) {
        string ticket = tickets[i][0];
        
        routes[ticket].push_back(tickets[i][1]);

        vector<string> s;  
        s.push_back("ICN");

        while(!s.empty()) {
            string airport = s.back();

            if(routes.find(airport) == routes.end() || routes[airport].size() == 0) {
                answer.push_back(airport);
                s.pop_back();

            } else {
                s.push_back(routes[airport].back());
                routes[airport].pop_back();
            }
        }
    }

    reverse(answer.begin(), answer.end());    
    return answer;
}

int main(void) {
    vector<vector<string> > tickets;

    vector<string> ticket;
    ticket.push_back("ICN");
    ticket.push_back("JFK");

    tickets.push_back(ticket);
    ticket.clear();

    ticket.push_back("HND");
    ticket.push_back("IAD");

    tickets.push_back(ticket);
    ticket.clear();

    ticket.push_back("JFK");
    ticket.push_back("HND");

    tickets.push_back(ticket);
    ticket.clear();

    vector<string> answer = solution(tickets);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }


}