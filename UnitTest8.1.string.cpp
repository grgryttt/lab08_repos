#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.8.1.string/MyMath.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8_1_4
{
    TEST_CLASS(UnitTest8_1_4)
    {
    public:

        // Викликає Change() і порівнює результат з очікуваним
        void CheckChange(const std::string& src, const std::string& exp)
        {
            Assert::AreEqual<std::string>(exp, Change(src));
        }

        // ---------- FindPair ----------

        TEST_METHOD(TestFindPair_Position)
        {
            Assert::AreEqual(2, (int)FindPair("xxbbaa"));  // "bb" раніше
        }

        TEST_METHOD(TestFindPair_EarliestOfThree)
        {
            Assert::AreEqual(1, (int)FindPair("abbcc"));  // "bb" раніше
        }

        TEST_METHOD(TestFindPair_FromPosition)
        {
            Assert::AreEqual(4, (int)FindPair("aaxxcc", 1)); // від позиції 1
        }

        TEST_METHOD(TestFindPair_NotFound)
        {
            Assert::IsTrue(FindPair("abab") == std::string::npos);
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
            Assert::IsFalse(HasPair("a b c a b c"));   // не сусідні
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
            std::string s = "aabb";
            std::string res = Change(s);
            Assert::AreEqual<std::string>("aabb", s);   // джерело не змінене
        }
    };
}
