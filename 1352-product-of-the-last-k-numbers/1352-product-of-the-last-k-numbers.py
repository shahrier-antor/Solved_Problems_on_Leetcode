class ProductOfNumbers:

    def __init__(self):
        self.prefixProduct = [1]
        self.lastZero = -1

    def add(self, num: int) -> None:
        if num == 0:
            self.lastZero = len(self.prefixProduct)
            self.prefixProduct.append(1*self.prefixProduct[-1])
        else:
            self.prefixProduct.append(num*self.prefixProduct[-1])

    def getProduct(self, k: int) -> int:
        if len(self.prefixProduct)-k <= self.lastZero:
            return 0
        else:
            return int(self.prefixProduct[-1]/self.prefixProduct[-1-k])


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)