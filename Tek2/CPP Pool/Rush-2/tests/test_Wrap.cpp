/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_Wrap
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../GiftPaper.hpp"
#include "../Box.hpp"
#include "../Teddy.hpp"
#include "../LittlePony.hpp"

Test(Box, should_create_box)
{
    Wrap *boite = new Box();
    std::string nameResult = boite->getName();
    bool isOpen = boite->getOpen();

    cr_assert_eq(nameResult, "Box");
    cr_assert_eq(isOpen, true);
}

Test(GiftPaper, should_open_and_close_wrap)
{
    Wrap *paper = new GiftPaper();
    bool isOpen = paper->getOpen();

    cr_assert_eq(isOpen, true);
    paper->closeMe();
    isOpen = paper->getOpen();
    cr_assert_eq(isOpen, false);
    paper->openMe();
    isOpen = paper->getOpen();
    cr_assert_eq(isOpen, true);
}

Test(Box, should_check_wrap)
{
    Object *ted = new Teddy("Bobo");
    Wrap *boite = new Box();

    boite->wrapMeThat(ted);
    cr_redirect_stderr();
    boite->wrapMeThat(ted);
    cr_assert_stderr_eq_str("Error: This Object already contains another Object\n");
}

Test(Box, should_not_wrap_that)
{
    Object *ted = new Teddy("Bibi");
    Wrap *boite = new Box();

    boite->closeMe();
    cr_redirect_stderr();
    boite->wrapMeThat(ted);
    cr_assert_stderr_eq_str("Error: Box is closed\n");
}

Test(GiftPaper, should_not_wrap_cause_not_box)
{
    Object *ted = new Teddy("Bibi");
    Wrap *paper = new GiftPaper();

    cr_redirect_stderr();
    paper->wrapMeThat(ted);
    cr_assert_stderr_eq_str("Error: Only Box can be wrapped\n");
}

Test(Box, should_not_wrap_cause_nullptr)
{
    Wrap *box = new Box();

    cr_redirect_stderr();
    box->wrapMeThat(nullptr);
    cr_assert_stderr_eq_str("Error: Object given is null\n");
}

Test(Box, should_return_is_a_toy)
{
    Wrap *box = new Box();
    Object *ted = new Teddy("Juanita");
    Object *pony = new LittlePony("Mattissou");
    bool result = box->isAToy(ted);

    cr_assert_eq(result, true);
    result = box->isAToy(pony);
    cr_assert_eq(result, true);
    result = box->isAToy(box);
    cr_assert_eq(result, false);
}

Test(Box, should_remove_wrap)
{
    Wrap *box = new Box();
    Object *toy = new Teddy("PeddoBear");

    box->wrapMeThat(toy);
    box->~Wrap();
    cr_assert_not_null(toy);
}

Test(Box, should_not_wrap_object)
{
    Wrap *box = new Box();
    Object *paper = new GiftPaper();

    cr_redirect_stderr();
    box->wrapMeThat(paper);
    cr_assert_stderr_eq_str("Error: Only Toys can be putted in Box\n");
}

Test(GiftPaper, should_remove_giftpaper)
{
    GiftPaper *paper = new GiftPaper();

    paper->~GiftPaper();
    cr_assert_not_null(paper);
}