#include "gtest/gtest.h"
#include "../includes/red_black_tree.h"

TEST(InsertTest, InsertOneNode) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(50);
  EXPECT_EQ(50, rb->root->key);
  EXPECT_EQ(1, rb->root->color);
}

TEST(InsertTest, LeftSideLineRotation) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(50);
  rb->insert(60);
  rb->insert(70);
  EXPECT_EQ(60, rb->root->key);
  EXPECT_EQ(1, rb->root->color);
  EXPECT_EQ(50, rb->root->left->key);
  EXPECT_EQ(0, rb->root->left->color);
  EXPECT_EQ(70, rb->root->right->key);
  EXPECT_EQ(0, rb->root->right->color);
}

TEST(InsertTest, RightSideLineRotation) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(70);
  rb->insert(60);
  rb->insert(50);
  EXPECT_EQ(60, rb->root->key);
  EXPECT_EQ(1, rb->root->color);
  EXPECT_EQ(50, rb->root->left->key);
  EXPECT_EQ(0, rb->root->left->color);
  EXPECT_EQ(70, rb->root->right->key);
  EXPECT_EQ(0, rb->root->right->color);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS();
}