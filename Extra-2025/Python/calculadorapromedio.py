import customtkinter as ctk

class CalcPorcentaje(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("Calculadora Notas")
        self.geometry("300x350")
        
        self.notas = []
        self.porcentajes = []

        ctk.CTkLabel(self, text="Introduzca la Nota: ").pack(pady=5)
        self.nota_i= ctk.CTkEntry(self)
        self.nota_i.pack(pady=5)

        ctk.CTkLabel(self, text="Introduzca el %: ").pack(pady=5)
        self.porcentaje_i = ctk.CTkEntry(self)
        self.porcentaje_i.pack(pady=5)

        ctk.CTkButton(self, text="Agregar Nota", command=self.agregar_nota).pack(pady=10)
        ctk.CTkButton(self, text="Calcular Final", command=self.calcular_final, fg_color="green").pack(pady=5)

        self.info_et = ctk.CTkLabel(self, text="")
        self.info_et.pack()

        self.res_et = ctk.CTkLabel(self, text="Resultado: --", font=("Arial", 20))
        self.res_et.pack(pady=20)

    def agregar_nota(self):
        try:
            notas = float(self.nota_i.get())
            porcentaje = float(self.porcentaje_i.get())
            self.notas.append(notas)
            self.porcentajes.append(porcentaje)
            
            self.nota_i.delete(0, 'end')
            self.nota_i.delete(0, 'end')
            self.info_et.configure(text=f"Notas guardadas: {len(self.notas)}")
        except:
            return

    def calcular_final(self):
        promedio = 0
        for i in range(len(self.notas)):
            promedio += self.notas[i] * (self.porcentajes[i] / 100)
        
        self.res_et.configure(text=f"Promedio Final: {promedio:.2f}")

if __name__ == "__main__":
    app = CalcPorcentaje()
    app.mainloop()