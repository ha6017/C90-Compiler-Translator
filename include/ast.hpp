#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_arith_op.hpp"
#include "ast/ast_assign_op.hpp"
#include "ast/ast_bitwise_op.hpp"
#include "ast/ast_cond_op.hpp"
#include "ast/ast_context.hpp"
#include "ast/ast_list.hpp"
#include "ast/ast_logical_op.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_variable_dec.hpp"
#include "ast/intermediate_rep.hpp"


extern const ASTNode *parseAST();

#endif
