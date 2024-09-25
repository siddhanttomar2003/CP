def go(bubbles, col, row):
    m = len(bubbles)
    row = min(row, m - 1)
    t = row
    for i in range(row, -1, -1):
        if bubbles[i][col] != 0:
            bubbles[t][col] = bubbles[i][col]
            t -= 1
    for t in range(t, -1, -1):
        bubbles[t][col] = 0

def solution(bubbles, operations):
    m, n = len(bubbles), len(bubbles[0])
    dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
    for operation in operations:
        x, y = operation[0], operation[1]
        if x < 0 or x >= m or y < 0 or y >= n or bubbles[x][y] == 0:
            continue
        c = 0
        color = bubbles[x][y]
        for d in range(4):
            xx, yy = x + dx[d], y + dy[d]
            if 0 <= xx < m and 0 <= yy < n and bubbles[xx][yy] == color:
                c += 1
        if c < 2:
            continue
        bubbles[x][y] = 0
        for d in range(4):
            xx, yy = x + dx[d], y + dy[d]
            if 0 <= xx < m and 0 <= yy < n and bubbles[xx][yy] == color:
                bubbles[xx][yy] = 0
                if yy != y:
                    go(bubbles, yy, x)
        go(bubbles, y, x + 1)

def print_bubbles(bubbles):
    for bubble in bubbles:
        for x in bubble:
            print(x, end=" ")
        print()
    print()