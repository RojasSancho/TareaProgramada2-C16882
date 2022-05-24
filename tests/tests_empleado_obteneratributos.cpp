#include <gtest/gtest.h>
#include "./../src/empleadoIndependientePorHoras.h"
#include "./../src/empleadoNomina.h"
#include <string>

namespace
{
    TEST(Test_Empleado_ObtenerAtributos, Test_ObtenerNombre)
    {
        //Arrange
        EmpleadoIndependientePorHoras *empleado = new EmpleadoIndependientePorHoras(4, "Alan", "Patel", "alan_patel@biz.com", 1, 1);


        //Act
        string actual = empleado->ObtenerNombre();
        string esperada = "Alan";

        //Assert
        EXPECT_EQ(esperada, actual);
    }
}