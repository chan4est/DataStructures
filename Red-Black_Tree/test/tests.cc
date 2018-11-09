#include "gtest/gtest.h"
#include "../includes/red_black_tree.h"

TEST(Insert, Root_Only) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(50);
  EXPECT_EQ(50, rb->root->key);
  EXPECT_EQ(1, rb->root->color);
}

TEST(Insert, Red_Uncle_Left) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(40);
  rb->insert(30);
  rb->insert(50);
  rb->insert(45);
  rb->insert(47);
  EXPECT_EQ(40, rb->root->key);
  EXPECT_EQ(1, rb->root->color);
  EXPECT_EQ(30, rb->root->left->key);
  EXPECT_EQ(1, rb->root->left->color);
  EXPECT_EQ(47, rb->root->right->key);
  EXPECT_EQ(1, rb->root->right->color);
  EXPECT_EQ(45, rb->root->right->left->key);
  EXPECT_EQ(0, rb->root->right->left->color);
  EXPECT_EQ(50, rb->root->right->right->key);
  EXPECT_EQ(0, rb->root->right->right->color);
}

TEST(Insert, Red_Uncle_Right) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(47);
  rb->insert(35);
  rb->insert(50);
  rb->insert(30);
  EXPECT_EQ(47, rb->root->key);
  EXPECT_EQ(1,  rb->root->color);
  EXPECT_EQ(35, rb->root->left->key);
  EXPECT_EQ(1,  rb->root->left->color);
  EXPECT_EQ(50, rb->root->right->key);
  EXPECT_EQ(1,  rb->root->right->color);
  EXPECT_EQ(30, rb->root->left->left->key);
  EXPECT_EQ(0,  rb->root->left->left->color);
}

TEST(Insert, Left_Left_Case) {
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

TEST(Insert, Right_Right_Case) {
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

TEST(Insert, Right_Left_Case) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(40);
  rb->insert(30);
  rb->insert(50);
  rb->insert(45);
  rb->insert(20);
  rb->insert(25);
  // Root
  EXPECT_EQ(40, rb->root->key);
  EXPECT_EQ(1,  rb->root->color);
  // Right Tree
  EXPECT_EQ(50, rb->root->right->key);
  EXPECT_EQ(1,  rb->root->right->color);
  EXPECT_EQ(45, rb->root->right->left->key);
  EXPECT_EQ(0,  rb->root->right->left->color);
  // Left Tree
  EXPECT_EQ(25, rb->root->left->key);
  EXPECT_EQ(1,  rb->root->left->color);
  EXPECT_EQ(20, rb->root->left->left->key);
  EXPECT_EQ(0,  rb->root->left->left->color);
  EXPECT_EQ(30, rb->root->left->right->key);
  EXPECT_EQ(0,  rb->root->left->right->color);
}

TEST(Insert, Multi_Rotation) {
  // https://goo.gl/WeiLbv
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(500);
  rb->insert(2);
  rb->insert(3);
  rb->insert(70);
  rb->insert(900);
  rb->insert(100);
  rb->insert(60);
  rb->insert(55);
  rb->insert(1);
  rb->insert(200);
  rb->insert(56);
  // Roots Only
  EXPECT_EQ(1,  rb->root->left->left->left->key);
  EXPECT_EQ(0,  rb->root->left->left->left->color);
  EXPECT_EQ(55, rb->root->left->right->left->key);
  EXPECT_EQ(0,  rb->root->left->right->left->color);
  EXPECT_EQ(60, rb->root->left->right->right->key);
  EXPECT_EQ(0,  rb->root->left->right->right->color);
  EXPECT_EQ(200, rb->root->right->left->right->key);
  EXPECT_EQ(0,   rb->root->right->left->right->color);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS();
}