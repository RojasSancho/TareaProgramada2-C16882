#include <gtest/gtest.h>
#include "./../src/empleadoNomina.h"

namespace
{
    TEST(Test_EmpleadoNomina_CalcularPagoNeto, Test_CalcularPagoNetoQuitandoImpuestos)
    {
        //Arrange
        EmpleadoNomina *empleado = new EmpleadoNomina(4133.06);


        //Act
        float actual = empleado->CalcularPagoNeto();
        float esperada = 3843.7458;

        //Assert
        EXPECT_FLOAT_EQ(esperada, actual);
    }
}