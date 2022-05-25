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

    TEST(Test_Empleado_ObtenerAtributos, Test_ObtenerApellido)
    {
        //Arrange
        EmpleadoIndependientePorHoras *empleado = new EmpleadoIndependientePorHoras(4, "Alan", "Patel", "alan_patel@biz.com", 1, 1);


        //Act
        string actual = empleado->ObtenerApellido();
        string esperada = "Patel";

        //Assert
        EXPECT_EQ(esperada, actual);
    }

    TEST(Test_Empleado_ObtenerAtributos, Test_ObtenerTipo1Nomina)
    {
        //Arrange
        EmpleadoIndependientePorHoras *empleado = new EmpleadoIndependientePorHoras(4, "Alan", "Patel", "alan_patel@biz.com", 1, 1);


        //Act
        int actual = empleado->ObtenerTipo();
        int esperada = 1;

        //Assert
        EXPECT_EQ(esperada, actual);
    }

    TEST(Test_Empleado_ObtenerAtributos, Test_ObtenerTipo2PorHoras)
    {
        //Arrange
        EmpleadoIndependientePorHoras *empleado = new EmpleadoIndependientePorHoras(589, "Johnny", "Walton", "Johnny_Walton5439@elnee.tech", 2, 286);


        //Act
        int actual = empleado->ObtenerTipo();
        int esperada = 2;

        //Assert
        EXPECT_EQ(esperada, actual);
    }
}