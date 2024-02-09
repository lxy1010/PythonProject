"""有一块 MxN 的土地, 雨后积水, 有水标记为'w', 干燥为'.'.八联通的积水被认为是连在一起的, 求院子里有多少水洼."""
"""为了计算院子里有多少个水洼，我们可以使用深度优先搜索（DFS）或广度优先搜索（BFS）来遍历整个土地"""
"""这里使用DFS深搜"""


class Traps:
    def __init__(self):
        self.grid = []
        self.M, self.N = None, None
        self.traps = 0

    def get_grid(self):
        """获取长宽及土地列表"""
        self.M, self.N = map(lambda x: int(x), input('输入 长&高: ').split(' '))
        self.grid = [list(input(f'第{i + 1}行,共{self.N}行: ')) for i in range(self.N)]

    def find_w(self):
        """遍历土地 若找到水洼 则进行dfs"""
        for i in range(self.N):
            for j in range(self.M):
                if self.grid[i][j] == 'w':
                    # 如果该地为水洼, 则执行dfs
                    self.dfs(i, j)
                    # 搜索完水洼后将水洼数+1
                    self.traps += 1

    def dfs(self, x, y):
        """深搜 dfs"""
        # 搜索后更改, 防止重复搜索
        self.grid[x][y] = '.'
        # 搜索八个方向
        for i in range(-1, 2):
            for j in range(-1, 2):
                # 防止数组越界
                if 0 <= x + i < self.N and 0 <= y + j < self.M:
                    # 若发现水洼, 再次进行dfs
                    if self.grid[x + i][y + j] == 'w':
                        self.dfs(x+i, y+j)

    def run(self):
        self.get_grid()
        self.find_w()
        print(f"Number of water traps: {self.traps}")


if __name__ == '__main__':
    Traps().run()
