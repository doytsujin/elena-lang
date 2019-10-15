[[
   #grammar build
   #grammar cf

   #define start          ::= "root" "(" namespace ")" $eof;            
   #define start          ::= $eof;

   #define namespace      ::= 
<= 
   system'dynamic'expressions'SymbolCollection ( 
=>
                                     "namespace" "(" member* ")"
<= ) =>;

   #define member         ::=
<= 
     system'dynamic'expressions'SymbolInfo ( 
=>
                                   "symbol" "(" s_name symbol_expr ")"
<=   ) =>;

  #define symbol_expr     ::= nested_symbol; 
                              
  #define nested_symbol   ::= 
<=
       system'dynamic'expressions'DynamicSingleton (
=>
                                   "nested" "(" method* ")"
<=     ) =>;

  #define method          ::= 
<=
       system'dynamic'expressions'MethodExpression (
=>
                                   "method" "(" m_name parameter* body ")"
<=
       )
=>;

  #define method          ::= 
<=
       system'dynamic'expressions'GetMethodExpression (
=>
                                   "get_method" "(" m_name body ")"
<=
       )
=>;

  #define parameter       ::= 
<=
         system'dynamic'expressions'ScopeVariable (
=>
                                   "parameter" "(" p_name ")"
<=
         )
=>;

  #define body            ::=
<=
             system'dynamic'expressions'CodeblockExpression (
=>
                                   "code" "(" statement* ")"
<=
             )
=>;

  #define statement       ::= expression; 
  #define statement       ::= ret_expression; 

  #define ret_expression  ::= 
<=
               system'dynamic'expressions'ReturnExpression (
=>
                                   expression
<=
               )
=>;

  #define expression      ::= "expression" "(" operation ")";

  #define operation       ::=
<=
               system'dynamic'expressions'GetPropertyExpression (
=>
                                 object message "property_parameter"
<=
               )
=>; 

  #define object          ::=
<=
                    Expression.Variable ( 
                       system'dynamic'expressions'ScopeVariable (
=>
                           "identifier" "(" ident_quote ")"
<=
                       )
                    )
=>;
      
  #define s_name          ::= "nameattr" "(" identifier ")" ;
  #define m_name          ::= "nameattr" "(" identifier ")" ;
  #define p_name          ::= "nameattr" "(" identifier ")" ;

  #define message         ::= "message" "=" ident_quote;
  #define identifier      ::= "identifier" "=" ident_quote;

  #define ident_quote  ::= <= "$identifier" =>;
]]