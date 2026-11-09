#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.8.1.3.1/MyMath.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8_1_3
{
    TEST_CLASS(UnitTest8_1_3)
    {
    public:

        // Викликає Change(), порівнює з очікуваним, звільняє пам'ять
        void CheckChange(const char* src, const char* expected)
        {
            char* res = Change(src);
            Assert::AreEqual(expected, res);
            delete[] res;
        }

        // ---------- FindPair ----------

        TEST_METHOD(TestFindPair_Position)
        {
            const char* s = "xxbbaa";
            Assert::AreEqual(2, (int)(FindPair(s) - s)); // "bb" раніше за "aa"
        }

        TEST_METHOD(TestFindPair_EarliestOfThree)
        {
            const char* s = "abbcc";
            Assert::AreEqual(1, (int)(FindPair(s) - s)); // "bb" раніше за "cc"
        }

        TEST_METHOD(TestFindPair_Null)
        {
            Assert::IsNull(FindPair("abab"));
        }

        // ---------- HasPair ----------

        TEST_METHOD(TestHasPair_aa)
        {
            Assert::IsTrue(HasPair("baab"));
        }

        TEST_METHOD(TestHasPair_bb)
        {
            Assert::IsTrue(HasPair("xxbbxx"));
        }

        TEST_METHOD(TestHasPair_cc)
        {
            Assert::IsTrue(HasPair("occ"));
        }

        TEST_METHOD(TestHasPair_NoPair)
        {
            Assert::IsFalse(HasPair("abcabc"));
        }

        TEST_METHOD(TestHasPair_NotNeighbours)
        {
            Assert::IsFalse(HasPair("a b c a b c"));   // однакові букви, але не сусідні
        }

        TEST_METHOD(TestHasPair_CaseSensitive)
        {
            Assert::IsFalse(HasPair("AAbBcC"));         // великі літери не рахуються
        }

        TEST_METHOD(TestHasPair_EmptyAndShort)
        {
            Assert::IsFalse(HasPair(""));
            Assert::IsFalse(HasPair("a"));
        }

        // ---------- Change ----------

        TEST_METHOD(TestChange_aa)
        {
            CheckChange("xaay", "x***y");
        }

        TEST_METHOD(TestChange_bb)
        {
            CheckChange("abba", "a***a");
        }

        TEST_METHOD(TestChange_cc)
        {
            CheckChange("occ", "o***");
        }

        TEST_METHOD(TestChange_AllThreePairs)
        {
            CheckChange("abbcca", "a******a");
        }

        TEST_METHOD(TestChange_WholeStringIsPairs)
        {
            CheckChange("aabbcc", "*********");
        }

        TEST_METHOD(TestChange_FourSameLetters)
        {
            CheckChange("bbbb", "******");          // дві пари поспіль
        }

        TEST_METHOD(TestChange_ThreeSameLetters)
        {
            CheckChange("aaa", "***a");             // пари не перекриваються
        }

        TEST_METHOD(TestChange_NoPairs)
        {
            CheckChange("abc abc", "abc abc");
        }

        TEST_METHOD(TestChange_CaseSensitive)
        {
            CheckChange("AAbBcC", "AAbBcC");
        }

        TEST_METHOD(TestChange_Empty)
        {
            CheckChange("", "");
        }

        TEST_METHOD(TestChange_DoesNotModifySource)
        {
            char s[] = "aabb";
            char* res = Change(s);
            Assert::AreEqual("aabb", s);            // рядок-джерело лишився без змін
            delete[] res;
        }
    };
}
