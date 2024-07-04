import numpy as np
def simple_dgemm():
    a = np.array([[1,2,3],[4,5,6]], dtype=np.float64)
    b = np.array([[1,2],[3,4],[5,6]], dtype=np.float64)
    c = a @ b # a.dot(b)
    print(c)

if __name__ == '__main__':
    simple_dgemm()