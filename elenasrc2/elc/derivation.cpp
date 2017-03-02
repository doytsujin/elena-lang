//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Compiler
//
//		This file contains ELENA Engine Derivation Tree class implementation
//
//                                              (C)2005-2017, by Alexei Rakov
//---------------------------------------------------------------------------

#include "elena.h"
// --------------------------------------------------------------------------
#include "derivation.h"

using namespace _ELENA_;

// --- DerivationWriter ---

//void DerivationWriter :: unpackNode(SNode& node, int mode)
//{
//   Symbol symbol = (Symbol)node.type;
//   switch (symbol) {
//      case nsClass:
//      case nsSymbol:
////      case nsStatic:
//      case nsMethod:
////      case nsConstructor:
////      case nsImplicitConstructor:
//      case nsField:
//      case nsSubject:
////      case nsDefaultGeneric:
//      case nsDispatchExpression:
//      case nsExtension:
////      case nsLoop:
////      case nsLock:
////      case nsExtern:
//      case nsScope:
//         _writer.newNode((LexicalType)(symbol & ~mskAnySymbolMask));
//         if (_hints != lxNone) {
//            copyHints(_hints);
//            _hints = lxNone;
//         }
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
//      case nsSubCode:
//         _writer.newNode(lxCode);
//         unpackChildren(node);
//         _writer.closeNode();
//         if (mode == 1) {
//            _writer.insert(lxExpression);
//            _writer.closeNode();
//         }
//         break;
////      case nsInlineExpression:
////      case nsInlineClosure:
////         unpackChildren(node);
////         _writer.insert(lxInlineExpression);         
////         _writer.closeNode();
////         if (mode == 1) {
////            _writer.insert(lxExpression);
////            _writer.closeNode();
////         }
////         break;
//      case nsNestedClass:
//         unpackChildren(node);
//         _writer.insert(lxNestedClass);
//         _writer.closeNode();
//         if (mode == 1) {
//            _writer.insert(lxExpression);
//            _writer.closeNode();
//         }
//         break;
//      case nsMessageReference:
//         _writer.newNode(lxExpression);
//         _writer.newNode(lxMessageReference);
//         unpackChildren(node);
//         _writer.closeNode();
//         _writer.closeNode();
//         break;
//      case nsImport:
//         _writer.newNode(lxImport);
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
////      case nsInclude:
////         _writer.newNode(lxInclude);
////         unpackChildren(node);
////         _writer.closeNode();
////         break;
//      case nsForward:
//         _writer.newNode(lxForward);
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
//      case nsBaseClass:
//         _writer.newNode(lxBaseParent);
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
//      case nsMethodParameter:
//         _writer.newNode(lxMethodParameter);
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
//      case nsSubjectArg:
//         _writer.newNode(lxMessage);
//         unpackChildren(node);
//         _writer.closeNode();
//         break;
//      case tsIdentifier:
////      case tsCharacter:
////      case tsHexInteger:
////      case tsLiteral:
//      case tsPrivate:
//      case tsReference:
//      case tsInteger:
////      case tsReal:
////      case tsLong:
////      case tsWide:
//         _writer.newNode((LexicalType)(symbol & ~mskAnySymbolMask | lxTerminalMask | lxObjectMask));
//         copyChildren(node);
//         _writer.closeNode();
//         break;
//      case nsRootExpression:
//         node = lxExpression;
//      case nsExpression:
////      case nsDispatchHandler:
//      case nsRetStatement:
//         copyExpression(node);
//         break;
//      case nsResendExpression:
//         _writer.newBookmark();
//         unpackChildren(node);
//
//         node = node.nextNode();
//         unpackNode(node, 0);
//
//         _writer.insert(lxResendExpression);
//         _writer.closeNode();
//
//         _writer.removeBookmark();
//         break;
//      case nsVariable:
//         copyVariable(node);
//         break;
//      case nsAssigning:
//         copyAssigning(node);
//         break;
////      case nsCatchMessageOperation:
////      case nsAltMessageOperation:
////         _writer.newBookmark();
//      case nsMessageOperation:
//         copyMessage(node);
//         _writer.insert(lxExpression);
//         _writer.closeNode();
//         //if (symbol == nsCatchMessageOperation) {
//         //   _writer.removeBookmark();            
//         //   _writer.insert(lxTrying);
//         //   _writer.closeNode();
//         //}
//         //else if (symbol == nsAltMessageOperation) {
//         //   _writer.removeBookmark();
//         //   _writer.insert(lxAlt);
//         //   _writer.closeNode();
//         //}
//         break;
////      case nsSwitching:
////         copySwitching(node);
////         _writer.insert(lxSwitching);
////         _writer.closeNode();
////         break;
////      case nsL0Operation:
//      case nsL3Operation:
//      case nsL4Operation:
////      case nsL5Operation:
//      case nsL6Operation:
//      case nsL7Operation:
////      case nsNewOperator:
//         copyMessage(node, true);
//         _writer.insert(lxExpression);
//         _writer.closeNode();
//         break;
//      case nsObject:
//         copyObject(node, mode);
//         break;
////      case nsThrow:
////         _writer.newNode(lxThrowing);
////         unpackChildren(node);
////         _writer.closeNode();
////         break;
//      case nsCodeEnd:
//         _writer.newNode(lxEOF);
//         copyChildren(node.firstChild());
//         _writer.closeNode();
//         break;
//      case nsToken:
//         if (_hints == lxNone) {
//            _hints = node;
//         }
//         break;
//      default:
//         break;
//   }
//}
//
//void DerivationWriter :: unpackChildren(SNode node, int mode)
//{
//   SNode current = node.firstChild();
//   while (current != lxNone) {
//      unpackNode(current, mode);
//
//      current = current.nextNode();
//   }
//}
//
//void DerivationWriter :: copyChildren(SNode node)
//{
//   SyntaxTree::copyNode(_writer, node);
//}
//
//void DerivationWriter :: copyExpression(SNode node, bool explicitOne)
//{
//   _writer.newBookmark();
//
//   unpackChildren(node, 1);
//
//   if (explicitOne) {
//      _writer.insert((LexicalType)(node.type & ~mskAnySymbolMask | lxExprMask));
//      _writer.closeNode();
//   }
//
//   _writer.removeBookmark();
//}
//
//void DerivationWriter :: copyObject(SNode node, int mode)
//{
//   int exprCounter = 0;
//   SNode current = node.firstChild();
//   while (current != lxNone) {
//      if (current == nsExpression)
//         exprCounter++;
//
//      unpackNode(current, mode);
//
//      current = current.nextNode();
//   }
//
//   if (mode == 1 && exprCounter > 1) {
//      _writer.insert(lxExpression);
//      _writer.closeNode();
//   }
//}
//
////void DerivationWriter :: copySwitching(SNode node)
////{
////   SNode current = node.firstChild();
////   while (current != lxNone) {
////      Symbol symbol = (Symbol)current.type;
////      switch (symbol) {
////         case nsSwitchOption:
////         case nsBiggerSwitchOption:
////         case nsLessSwitchOption:
////            _writer.newBookmark();
////            unpackChildren(current);
////            if (symbol == nsBiggerSwitchOption) {
////               _writer.insert(lxOption, GREATER_MESSAGE_ID);
////            }
////            else if (symbol == nsLessSwitchOption) {
////               _writer.insert(lxOption, LESS_MESSAGE_ID);
////            }
////            else _writer.insert(lxOption, EQUAL_MESSAGE_ID);
////            _writer.closeNode();
////            _writer.removeBookmark();
////            break;
////         case nsLastSwitchOption:
////            _writer.newBookmark();
////            unpackChildren(current);
////            _writer.insert(lxElse);
////            _writer.closeNode();
////            _writer.removeBookmark();
////            break;
////         default:
////            break;
////      }
////      current = current.nextNode();
////   }
////}
//
//void DerivationWriter :: copyMessage(SNode node, bool operationMode)
//{
//   SNode current = node.firstChild();
//   while (current != lxNone) {
//      Symbol symbol = (Symbol)current.type;
//      switch (symbol) {
//         case nsSubjectArg:
//            _writer.newNode(lxMessage);
//            unpackChildren(current);
//            _writer.closeNode();
//            break;
//         case nsMessageParameter:
//         case nsObject:
//         case nsExpression:
//            _writer.newBookmark();
//            unpackChildren(current, 1);
//            _writer.removeBookmark();
//            break;
//         //case nsElseOperation:
//         //   _writer.newNode(lxExpression);
//         //   unpackChildren(current);
//         //   _writer.closeNode();
//         //   break;
//         case nsSubCode:
//            unpackNode(current, 1);
//            break;
//         //case nsL0Operation:
//         //case nsL3Operation:
//         //case nsL4Operation:
//         //case nsL5Operation:
//         //case nsL6Operation:
//         //case nsL7Operation:
//         //case nsNewOperator:
//         case nsMessageOperation:
//            copyMessage(current, (symbol != nsMessageOperation));
//            _writer.insert(lxExpression);
//            _writer.closeNode();
//            break;
//         case tsIdentifier:
//         case tsPrivate:
//         case tsReference:
//            if (!operationMode) {
//               _writer.newNode(lxMessage);
//               unpackNode(current, 0);
//               _writer.closeNode();
//               break;
//            }
//         default:
//            if (operationMode && current.existChild(lxTerminal)) {
//               //if ((Symbol)node.type == nsNewOperator) {
//               //   //HOTFIX : mark new operator
//               //   _writer.appendNode(lxOperator, -1);
//               //   if (symbol == tsInteger || symbol == tsIdentifier) {
//               //      unpackNode(current, 0);
//               //   }
//               //}
//               //else {
//                  _writer.newNode(lxOperator);
//                  copyChildren(current);
//                  _writer.closeNode();
//               //}
//
//               _writer.newBookmark();               
//            }
//            break;
//      }
//      current = current.nextNode();
//   }
//
//   if (operationMode) {
//      _writer.removeBookmark();
//   }
//}
//
//void DerivationWriter :: copyVariable(SNode node)
//{
//   SNode local = node.firstChild();
//
//   _writer.newNode(lxVariable);
//
//   if (_hints != lxNone) {
//      copyHints(_hints);
//      _hints = lxNone;
//   }
//
//   unpackNode(local, 0);
//   _writer.closeNode();
//
//   SNode current = node.findChild((LexicalType)nsAssigning);
//   if (current != lxNone) {
//      _writer.newNode(lxExpression);
//      _writer.appendNode(lxAssign);
//      unpackNode(local, 1);
//
//      unpackChildren(current);
//
//      _writer.closeNode();
//   }
//}
//
//void DerivationWriter :: copyAssigning(SNode node)
//{
//   _writer.appendNode(lxAssign);
//
//   unpackChildren(node);
//}
//
//void DerivationWriter :: copyHints(SNode current)
//{
//   while (((LexicalType)current.type) == nsToken) {
//      _writer.newNode(lxAttribute);
//      unpackChildren(current);
//      _writer.closeNode();
//
//      current = current.nextNode();
//   }
//}

void DerivationWriter :: writeNode(Symbol symbol)
{
   switch (symbol)
   {
      case nsImport:
         _writer.newNode(lxImport);
         break;
      case nsToken:
         _writer.newNode(lxAttribute);
         break;
      case nsExpression:
      case nsRootExpression:
         _writer.newNode(lxExpression);
         break;
      case nsCodeEnd:
         _writer.newNode(lxEOF);
         break;
      case nsMethodParameter:
         _writer.newNode(lxMethodParameter);
         break;
      case nsForward:
         _writer.newNode(lxForward);
         break;
      case nsMessageParameter:
         _writer.newNode(lxMessageParameter);
         break;
      case nsNestedClass:
         _writer.newNode(lxNestedClass);
         break;
      case nsAssigning:
         _writer.newNode(lxAssigning);
         break;
      case nsResendExpression:
         _writer.newNode(lxResendExpression);
         break;
      case nsObject:
         _writer.newNode(lxObject);
         break;
      case nsBaseClass:
         _writer.newNode(lxBaseParent);
         break;
      case nsL0Operation:
      case nsL3Operation:
      case nsL4Operation:
      case nsL5Operation:
      case nsL6Operation:
      case nsL7Operation:
         _writer.newNode(lxOperator);
         break;
      case nsMessageOperation:
         _writer.newNode(lxMessage);
         break;
      case nsSubjectArg:
         _writer.newNode(lxMessage, -1);
         break;
      case nsRetStatement:
         _writer.newNode((LexicalType)(symbol & ~mskAnySymbolMask | lxExprMask));
         break;
      case nsMessageReference:
         _writer.newNode(lxMessageReference);
         break;
      case nsSubCode:
      case nsScope:
      case nsTemplate:
      case nsTokenParam:
      case nsSubject:
      case nsDispatchExpression:
      case nsExtension:
      case nsLoop:
      case nsDefaultGeneric:
      case nsCatchMessageOperation:
      case nsAltMessageOperation:
         _writer.newNode((LexicalType)(symbol & ~mskAnySymbolMask));
         break;
      default:
         _writer.newNode((LexicalType)symbol);
         break;
   }   
}

void DerivationWriter :: writeSymbol(Symbol symbol)
{
   if (symbol != nsNone) {
      writeNode(symbol);
   }
   else _writer.closeNode();
}

void DerivationWriter :: writeTerminal(TerminalInfo& terminal)
{
   // HOT FIX : if there are several constants e.g. #10#13, it should be treated like literal terminal
   if (terminal == tsCharacter && terminal.value.findSubStr(1, '#', terminal.length, NOTFOUND_POS) != NOTFOUND_POS) {
      terminal.symbol = tsLiteral;
   }

   _writer.newNode((LexicalType)(terminal.symbol & ~mskAnySymbolMask | lxTerminalMask | lxObjectMask));

   if (terminal==tsLiteral || terminal==tsCharacter || terminal==tsWide) {
      // try to use local storage if the quote is not too big
      if (getlength(terminal.value) < 0x100) {
         QuoteTemplate<IdentifierString> quote(terminal.value);
      
         _writer.appendNode(lxTerminal, quote.ident());
      }
      else {
         QuoteTemplate<DynamicString<char> > quote(terminal.value);
      
         _writer.appendNode(lxTerminal, quote.ident());
      }
   }
   else _writer.appendNode(lxTerminal, terminal.value);

   _writer.appendNode(lxCol, terminal.col);
   _writer.appendNode(lxRow, terminal.row);
   _writer.appendNode(lxLength, terminal.length);
   //   _writer->writeDWord(terminal.disp);

   _writer.closeNode();
}
