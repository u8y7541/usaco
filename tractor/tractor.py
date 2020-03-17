class UnionFind:
	def __init__(self, n):
		self.parents = list(range(n))
		self.sizes = [1]*n

	def find(self, x):
		if self.parents[x] != x:
			return self.find(self.parents[x])
		return x

	def union(self, x, y):
		x_root = self.find(x)
		y_root = self.find(y)
		if self.sizes[x_root]>self.sizes[y_root]:
			self.parents[y_root] = x_root
			self.sizes[x_root] += self.sizes[y_root]
		else:
			self.parents[x_root] = y_root
			self.sizes[y_root] += self.sizes[x_root]

	def connected(self, x, y):
		return (self.find(x) == self.find(y))

	def size(self, x):
		return self.sizes[x]

i = open('tractor.in')
text = i.read().split()
i.close()

N = int(text[0])
data = [[int(j) for j in text[i:i+N]] for i in range(1, len(text[1:]), N)]
print(data)
