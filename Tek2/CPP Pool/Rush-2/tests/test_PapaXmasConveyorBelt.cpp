/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_PapaXmasConveyorBelt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../PapaXmasConveyorBelt.hpp"
#include "../Box.hpp"

Test(PapaXmasConveyorBelt, should_create_papaxmasconveyorbelt)
{
    PapaXmasConveyorBelt *belt = new PapaXmasConveyorBelt();
    bool resultBox = belt->getBool();

    cr_assert_eq(resultBox, true);
}

Test(PapaXmasConveyorBelt, should_create_conveyor_belt)
{
    PapaXmasConveyorBelt *belt = new PapaXmasConveyorBelt();
    IConveyorBelt *result = belt->createConveyorBelt();

    cr_assert_not_null(result);
}

Test(PapaXmasConveyorBelt, should_push_in_button)
{
    PapaXmasConveyorBelt *belt = new PapaXmasConveyorBelt();
    Object *result = belt->getObject();
    std::string resultType;

    cr_assert_eq(result, nullptr);
    belt->in();
    result = belt->getObject();
    resultType = result->getType();
    cr_assert_eq(resultType, BOX);
    cr_redirect_stderr();
    belt->in();
    cr_assert_stderr_eq_str("Error: ConveyorBelt has already an Object\n");
}

Test(PapaXmasConveyorBelt, should_push_in_button_and_get_giftpaper)
{
    PapaXmasConveyorBelt *belt = new PapaXmasConveyorBelt();
    Object *result;
    std::string resultType;

    belt->in();
    belt->takeObject();
    belt->in();
    result = belt->getObject();
    resultType = result->getType();
    cr_assert_eq(resultType, PAPER);
}
