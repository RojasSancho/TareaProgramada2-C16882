#include <gtest/gtest.h>
#include "./../src/empleadoIndependientePorHoras.h"

namespace
{
    TEST(Test_EmpleadoIndependientePorHoras_CalcularPagoNeto, Test_CalcularPagoNetoEmpleadoPorHoras)
    {
        //Arrange
        EmpleadoIndependientePorHoras *empleado = new EmpleadoIndependientePorHoras(58.33, 10);


        //Act
        float actual = empleado->CalcularPagoNeto();
        float esperada = 583.3;

        //Assert
        EXPECT_FLOAT_EQ(esperada, actual);
    }
}