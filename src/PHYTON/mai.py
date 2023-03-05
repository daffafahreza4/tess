class Calculator:
  def __init__(self, result):
    self.result = result

  def tambah(self, x, y):
    result = x + y
    print("Hasil dari ", x, " + ", y, " adalah :", result)

  def kurang(self, x, y):
    result = x - y
    print("Hasil dari ", x, " - ", y, " adalah :", result)


  def kali(self, x, y):
    result = x * y
    print("Hasil dari ", x, " * ", y, " adalah :", result)

  def bagi(self, x, y):
    result = x / y
    print("Hasil dari ", x, " / ", y, " adalah :", result)


calculator = Calculator(0)
calculator.tambah(10,10)