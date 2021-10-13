def isAvailable(candidate, current_col):
    current_row = len(candidate)
    for queen_row in range(current_row):
        # queen이 현재 column에 위치하여 있는 경우
        # candidate[queen_row] == queen의 col
        # abs(candidate[queen_row] - current_col) == current_row - queen_row ==> queen이 대각선에 위치하여 있는 경우
        if candidate[queen_row] == current_col or abs(candidate[queen_row] - current_col) == current_row - queen_row:
            return False
    return True

def DFS(N, current_row, current_candidate, result):
    if current_row == N: # 마지막 행이라면
        result.append(current_candidate[:]) # 남은 candidate를 result에 삽입
        return 
    
    for candidate_col in range(N): # 행의 길이만큼 반복
        # current_candidate가 isAvailable() 조건에 만족한다면
        if isAvailable(current_candidate, candidate_col):
            current_candidate.append(candidate_col)
            DFS(N, current_row + 1, current_candidate, result)
            current_candidate.pop() # DFS에서 맞지 않는 조건을 찾을 경우 아무것도 리턴되지 않기에, 가장 최근에 append 했던 것이 제거 (backtrack) 
            
def solve_n_queens(num):
    result = []
    DFS(num, 0, [], result)
    return result

solve_n_queens(4)
