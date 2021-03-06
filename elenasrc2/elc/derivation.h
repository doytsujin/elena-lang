//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Compiler
//               
//		This file contains ELENA Engine Derivation Tree classes
//
//                                              (C)2005-2020, by Alexei Rakov
//---------------------------------------------------------------------------

#ifndef derivationH
#define derivationH 1

#include "parser.h"
#include "compilercommon.h"

namespace _ELENA_
{

// --- DerivationWriter ---

//typedef Map<ident_t, char*> TypedMap;

class DerivationWriter : public _DerivationWriter
{
   enum class MetaScope : int
   {
      None,
      Namespace,
      Type,
//   //      daClass       = 0x0002,
//      daTemplate    = 0x0004,
//      daProperty    = 0x0008,
//      daInline      = 0x0010,
      Import,
//      daExtension   = 0x8000,
   };

   enum ScopeType
   {
      stNormal = 0,
      stClassTemplate,
      stCodeTemplate,
      stPropertyTemplate,
      stExtensionTemplate,
      stInlineTemplate
   };

   struct Scope
   {
      ScopeType      templateMode;
      ForwardMap     parameters;
      int            nestedLevel;
      bool           ignoreTerminalInfo;
      int            bookmark;

      bool isNameParameter(ident_t name, ref_t& argument)
      {
         if (/*templateMode == stInlineTemplate || */templateMode == stPropertyTemplate) {
            ref_t index = parameters.get(name);
            if (index == parameters.Count()) {
               argument = nestedLevel + index;

               return true;
            }
            else return false;
         }
         else return false;
      }

//      bool isMessageParameter(ident_t name, ref_t& argument)
//      {
//         if (templateMode == stPropertyTemplate) {
//            int index = parameters.get(name);
//            if (index) {
//               argument = index;
//
//               return true;
//            }
//         }
//         return false;
//      }
//
//      bool isTypeParameter(ident_t name, ref_t& argument)
//      {
//         if (withTypeParameters()) {
//            int index = parameters.get(name);
//            if (index) {
//               argument = index + nestedLevel;
//
//               return true;
//            }
//         }
//         return false;
//      }

      bool isIdentifierParameter(ident_t name, ref_t& argument)
      {
         if (withTypeParameters()) {
            int index = parameters.get(name);
            if (index) {
               argument = index + nestedLevel;

               return true;
            }
         }
         return false;
      }

      bool withTypeParameters() const
      {
         return templateMode == stClassTemplate || templateMode == stPropertyTemplate
            || templateMode == stExtensionTemplate;
      }

      Scope()
      {
         templateMode = ScopeType::stNormal;
         nestedLevel = 0;
         ignoreTerminalInfo = false;
         bookmark = 0;
      }
   };

   int           _level;
   int           _cachingLevel;
   SyntaxTree    _cache;
   SyntaxWriter  _cacheWriter;

   SyntaxWriter  _output;

   _ModuleScope* _scope;
//   ident_t       _ns;
//   ident_t       _filePath;
//   IdentifierList _importedNs;

   void loadTemplateParameters(Scope& scope, SNode node);
   void loadTemplateExprParameters(Scope& scope, SNode node);

   MetaScope recognizeMetaScope(SNode node);

   void saveScope(SyntaxWriter& writer);

   ref_t resolveTemplate(ident_t templateName);

   ref_t mapAttribute(SNode terminal, bool allowType, bool& allowPropertyTemplate, ref_t& previusCategory);
   ref_t mapInlineAttribute(SNode terminal);
   void declareAttribute(SNode node);
   void declareStatement(SNode node, ScopeType templateType);

   void recognizeAttributes(SNode node, int mode, LexicalType nameType);

   void recognizeScope();
   void recognizeDefinition(SNode scopeNode);
   void recognizeScopeAttributes(SNode node, int mode);
   void recognizeClassMebers(SNode node);
   void recognizeMethodMebers(SNode node);

 //  bool recognizeMetaScope(SNode node);

   void declareNestedNamespace(SNode node, Scope& derivationScope);

   void saveTemplateParameters(SyntaxWriter& tempWriter, SNode current, Scope& derivationScope);

   void copyScope(SyntaxWriter& writer, SNode node, Scope& derivationScope);

   void generateOperatorTemplateTree(SyntaxWriter& writer, SNode& current, Scope& derivationScope);
   void generateClassImport(SyntaxWriter& writer, SNode node, Scope& derivationScope, SyntaxTree& buffer);
   void generateTemplateTree(SNode node, ScopeType templateType);
   void generateScope(SyntaxWriter& writer, SNode node, Scope& scope);
   void generateClosureTree(SyntaxWriter& writer, SNode& node, Scope& derivationScope);
   void generateStatementTemplateTree(SyntaxWriter& writer, SNode node, SyntaxTree& tempTree, ident_t templateName, 
      Scope& derivationScope);
   void generateStatementTemplateTree(SyntaxWriter& writer, SNode& node, Scope& derivationScope);
   void generatePropertyBody(SyntaxWriter& writer, SNode node, Scope& derivationScope, /*List<SNode>* parameters, */SyntaxTree& buffer);
   void generatePropertyTemplateTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, SyntaxTree& buffer);
   void generateInlineTemplateTree(SyntaxWriter& writer, SNode node, SNode owner, Scope& derivationScope, SyntaxTree& buffer);
   //void generateClassTemplateTree(SyntaxWriter& writer, SNode node, Scope& derivationScope);
//   //void generateMetaTree(SyntaxWriter& writer, SNode node, Scope& derivationScope);
   void generateSymbolTree(SyntaxWriter& writer, SNode node, Scope& derivationScope);
   void generateClassTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, bool nested = false);
   void generateMethodTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, bool functionMode, bool propertyMode, SyntaxTree& buffer);
//   // returns true if in-place init found
   void generatePropertyTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, SyntaxTree& buffer);
   void generateFieldTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, SyntaxTree& buffer);
   void generateCodeTree(SyntaxWriter& writer, SNode node, Scope& derivationScope/*, bool withBookmark = false*/);
   void generateTokenExpression(SyntaxWriter& writer, SNode& node, Scope& derivationScope/*, bool rootMode*/);
   void generateTypeAttribute(SyntaxWriter& writer, SNode terminal, ref_t typeRef, int dimensionCounter, 
      Scope& derivationScope);
   void generateAttributes(SyntaxWriter& writer, SNode node, Scope& derivationScope, SyntaxTree& buffer);
   void generateTemplateAttributes(SyntaxWriter& writer, SNode node, Scope& derivationScope);
   void generateExpressionAttribute(SyntaxWriter& writer, SNode node, Scope& derivationScope, ref_t& previousCategory, 
      int dimensionCounter, bool templateArgMode = false/*, bool onlyAttributes = false*/);
   void generateExpressionTree(SyntaxWriter& writer, SNode node, Scope& derivationScope, int mode = 0);
   void generateExpressionNode(SyntaxWriter& writer, SNode& current, bool& first, bool& expressionExpected, Scope& derivationScope);
   void generateCollectionTree(SyntaxWriter& writer, SNode node, Scope& derivationScope);
   void generateSwitchTree(SyntaxWriter& writer, SNode current, Scope& derivationScope);
   void generateCodeExpression(SyntaxWriter& writer, SNode node, Scope& derivationScope, bool closureMode);
   void generateIdentifier(SyntaxWriter& writer, SNode current, Scope& derivationScope);
   void generateMesage(SyntaxWriter& writer, SNode current, Scope& derivationScope);

   void declareType(SNode node);
   void generateImport(SyntaxWriter& writer, SNode ns);

   void raiseError(ident_t err, SNode node);
   void raiseWarning(int level, ident_t msg, SNode node);

   void appendFilePath(SNode node, IdentifierString& path);

public:
   void newNodeDirectly(LexicalType symbol);
   void newNodeDirectly(LexicalType symbol, ident_t arg);
   void closeNodeDirectly();

   virtual void newNode(LexicalType symbol);
   virtual void appendTerminal(TerminalInfo& terminal);
   virtual void closeNode();

   DerivationWriter(SyntaxTree& target, _ModuleScope* scope)
      :  _output(target), _cacheWriter(_cache)//, _importedNs(nullptr, freestr)
   {
      _cachingLevel = _level = 0;

      _scope = scope;

      _cacheWriter.newNode(lxRoot);
   }
};

// --- TemplateGenerator ---

class TemplateGenerator
{
   typedef Map<int, SNode> NodeMap;

   // --- TemplateScope ---
   struct TemplateScope
   {
      enum Type
      {
         ttClassTemplate    = 0,
         ttPropertyTemplate = 1,
         ttCodeTemplate     = 3,
         ttInlineTemplate   = 4
      };

      Type          type;
      ref_t         templateRef;
      ref_t         reference;
      NodeMap       parameterValues;

      _Module*      templateModule;
      _ModuleScope* moduleScope;

      ident_t       ns;
      ident_t       sourcePath;
//
//      bool          importMode;
//
//      bool withTypeParameters()
//      {
//         return type == ttPropertyTemplate || type == ttClassTemplate;
//      }

      bool generateClassName();

      _Memory* loadTemplateTree();

      TemplateScope(_ModuleScope* moduleScope, ref_t templateRef, ident_t sourcePath, ident_t ns/*, IdentifierList* imports*/)
         : parameterValues(SNode())
      {
         this->sourcePath = sourcePath;
         this->ns = ns;

         this->moduleScope = moduleScope;

         type = Type::ttClassTemplate;
         this->templateRef = templateRef;
         this->reference = 0;
         this->templateModule = nullptr;
//         this->importMode = false;
      }
   };

////   SNode       _root;

   void copyNodes(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyChildren(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyFieldInitTree(SyntaxWriter& writer, SNode node, TemplateScope& scope, int bookmark);
   void copyFieldTree(SyntaxWriter& writer, SNode node, TemplateScope& scope, int bookmark);
   void copyExpressionTree(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyTreeNode(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyMethodTree(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyModuleInfo(SyntaxWriter& writer, SNode node, TemplateScope& scope);
   void copyTemplateIdenParam(SyntaxWriter& writer, SNode nodeToInject, TemplateScope& scope);

   bool generateTemplate(SyntaxWriter& writer, TemplateScope& scope, bool declaringClass, 
      bool importModuleInfo, int bookmark);

public:
   ref_t declareTemplate(SyntaxWriter& writer, _ModuleScope& scope, ref_t reference, List<SNode>& parameters);
   ref_t generateTemplate(SyntaxWriter& writer, _ModuleScope& scope, ref_t reference, List<SNode>& parameters,
                           bool importModuleInfo, bool importMode);

   void generateTemplateCode(SyntaxWriter& writer, _ModuleScope& scope, ref_t reference, List<SNode>& parameters);
   void generateTemplateProperty(SyntaxWriter& writer, _ModuleScope& scope, ref_t reference, 
      List<SNode>& parameters, int bookmark, bool inlineMode);

   void importClass(SyntaxWriter& output, SNode node);

   TemplateGenerator(SyntaxTree& tree);
};

} // _ELENA_

#endif // derivationH
