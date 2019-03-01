#ifndef ast_hpp
#define ast_hpp

#include "ast_arith_op.hpp"
#include "ast_assign_op.hpp"
#include "ast_bitwise_op.hpp"
#include "ast_cond_op.hpp"
#include "ast_context.hpp"
#include "ast_list.hpp"
#include "ast_logical_op.hpp"
#include "ast_node.hpp"
#include "ast_primitives.hpp"
#include "ast_variable_dec.hpp"
#include "intermediate_rep.hpp"


extern const ASTNode *parseAST();

#endif
