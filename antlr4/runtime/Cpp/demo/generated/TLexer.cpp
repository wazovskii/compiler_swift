/* lexer header section */

// Generated from /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/TLexer.g4 by ANTLR 4.9.1

/* lexer precinclude section */

#include "TLexer.h"


/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


using namespace antlr4;

using namespace antlrcpptest;

TLexer::TLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TLexer::~TLexer() {
  delete _interpreter;
}

std::string TLexer::getGrammarFileName() const {
  return "TLexer.g4";
}

const std::vector<std::string>& TLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& TLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& TLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& TLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& TLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> TLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& TLexer::getATN() const {
  return _atn;
}

/* lexer definitions section */

void TLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 24: FooAction(dynamic_cast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: BarAction(dynamic_cast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 24: return FooSempred(dynamic_cast<antlr4::RuleContext *>(context), predicateIndex);
    case 25: return BarSempred(dynamic_cast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void TLexer::FooAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  myFooLexerAction();  break;

  default:
    break;
  }
}

void TLexer::BarAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  myBarLexerAction();  break;

  default:
    break;
  }
}


bool TLexer::FooSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return canTestFoo();
    case 1: return isItFoo();

  default:
    break;
  }
  return true;
}

bool TLexer::BarSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return isItBar();

  default:
    break;
  }
  return true;
}


// Static vars and initialization.
std::vector<dfa::DFA> TLexer::_decisionToDFA;
atn::PredictionContextCache TLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TLexer::_atn;
std::vector<uint16_t> TLexer::_serializedATN;

std::vector<std::string> TLexer::_ruleNames = {
  "Return", "Continue", "INT", "Digit", "ID", "LETTER", "LessThan", "GreaterThan", 
  "Equal", "And", "Colon", "Semicolon", "Plus", "Minus", "Star", "OpenPar", 
  "ClosePar", "OpenCurly", "CloseCurly", "QuestionMark", "Comma", "Dollar", 
  "Ampersand", "String", "Foo", "Bar", "Any", "Comment", "WS", "Baz", "Dot", 
  "DotDot"
};

std::vector<std::string> TLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN", "CommentsChannel", "DirectiveChannel"
};

std::vector<std::string> TLexer::_modeNames = {
  "DEFAULT_MODE", "Mode1", "Mode2"
};

std::vector<std::string> TLexer::_literalNames = {
  "", "", "'return'", "'continue'", "", "", "", "'<'", "'>'", "'='", "'and'", 
  "':'", "';'", "'+'", "'-'", "'*'", "'('", "')'", "'{'", "'}'", "'\u003F'", 
  "','", "", "", "", "", "", "", "'.'", "'..'", "'$'", "'&'"
};

std::vector<std::string> TLexer::_symbolicNames = {
  "", "DUMMY", "Return", "Continue", "INT", "Digit", "ID", "LessThan", "GreaterThan", 
  "Equal", "And", "Colon", "Semicolon", "Plus", "Minus", "Star", "OpenPar", 
  "ClosePar", "OpenCurly", "CloseCurly", "QuestionMark", "Comma", "String", 
  "Foo", "Bar", "Any", "Comment", "WS", "Dot", "DotDot", "Dollar", "Ampersand"
};

dfa::Vocabulary TLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TLexer::_tokenNames;

TLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x2, 0x21, 0xd3, 0x8, 0x1, 0x8, 0x1, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 
    0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 
    0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 
    0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 
    0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 
    0x11, 0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
    0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 
    0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 
    0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 
    0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 
    0x9, 0x21, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x6, 0x4, 0x57, 0xa, 0x4, 0xd, 
    0x4, 0xe, 0x4, 0x58, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x60, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x63, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x98, 0xa, 0x19, 0xc, 0x19, 
    0xe, 0x19, 0x9b, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xb1, 0xa, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0xb8, 0xa, 0x1d, 
    0xc, 0x1d, 0xe, 0x1d, 0xbb, 0xb, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0xbe, 0xa, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x6, 0x1e, 
    0xc5, 0xa, 0x1e, 0xd, 0x1e, 0xe, 0x1e, 0xc6, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x99, 0x2, 0x22, 0x5, 0x4, 0x7, 0x5, 0x9, 
    0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x2, 0x11, 0x9, 0x13, 0xa, 0x15, 0xb, 
    0x17, 0xc, 0x19, 0xd, 0x1b, 0xe, 0x1d, 0xf, 0x1f, 0x10, 0x21, 0x11, 
    0x23, 0x12, 0x25, 0x13, 0x27, 0x14, 0x29, 0x15, 0x2b, 0x16, 0x2d, 0x17, 
    0x2f, 0x20, 0x31, 0x21, 0x33, 0x18, 0x35, 0x19, 0x37, 0x1a, 0x39, 0x1b, 
    0x3b, 0x1c, 0x3d, 0x1d, 0x3f, 0x2, 0x41, 0x1e, 0x43, 0x1f, 0x5, 0x2, 
    0x3, 0x4, 0x5, 0x3, 0x2, 0x32, 0x3b, 0x4, 0x2, 0xc, 0xc, 0xf, 0xf, 0x5, 
    0x2, 0xb, 0xc, 0xf, 0xf, 0x22, 0x22, 0x3, 0x5, 0x2, 0x43, 0x2, 0x5c, 
    0x2, 0x63, 0x2, 0x7c, 0x2, 0x82, 0x2, 0x1, 0x12, 0xd6, 0x2, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x43, 0x3, 0x2, 0x2, 0x2, 0x5, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x7, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x9, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0xb, 0x5a, 0x3, 0x2, 0x2, 0x2, 0xd, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xf, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x11, 0x66, 0x3, 0x2, 0x2, 0x2, 0x13, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x17, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x19, 0x70, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x74, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x78, 0x3, 0x2, 0x2, 0x2, 0x23, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x27, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x29, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0x86, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x31, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x95, 0x3, 0x2, 0x2, 0x2, 0x35, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x39, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x3d, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0xca, 0x3, 0x2, 0x2, 0x2, 0x41, 0xce, 0x3, 0x2, 0x2, 0x2, 0x43, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x74, 0x2, 0x2, 0x46, 0x47, 0x7, 
    0x67, 0x2, 0x2, 0x47, 0x48, 0x7, 0x76, 0x2, 0x2, 0x48, 0x49, 0x7, 0x77, 
    0x2, 0x2, 0x49, 0x4a, 0x7, 0x74, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x70, 0x2, 
    0x2, 0x4b, 0x6, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x65, 0x2, 0x2, 
    0x4d, 0x4e, 0x7, 0x71, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x70, 0x2, 0x2, 0x4f, 
    0x50, 0x7, 0x76, 0x2, 0x2, 0x50, 0x51, 0x7, 0x6b, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x70, 0x2, 0x2, 0x52, 0x53, 0x7, 0x77, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x67, 0x2, 0x2, 0x54, 0x8, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x5, 0xb, 
    0x5, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0xa, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x9, 0x2, 0x2, 0x2, 0x5b, 
    0xc, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x61, 0x5, 0xf, 0x7, 0x2, 0x5d, 0x60, 
    0x5, 0xf, 0x7, 0x2, 0x5e, 0x60, 0x4, 0x32, 0x3b, 0x2, 0x5f, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0xe, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x65, 0x9, 0x5, 0x2, 0x2, 0x65, 0x10, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x67, 0x7, 0x3e, 0x2, 0x2, 0x67, 0x12, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x7, 0x40, 0x2, 0x2, 0x69, 0x14, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 
    0x3f, 0x2, 0x2, 0x6b, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x63, 
    0x2, 0x2, 0x6d, 0x6e, 0x7, 0x70, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x66, 0x2, 
    0x2, 0x6f, 0x18, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x3c, 0x2, 0x2, 
    0x71, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x3d, 0x2, 0x2, 0x73, 
    0x1c, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x2d, 0x2, 0x2, 0x75, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x2f, 0x2, 0x2, 0x77, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x2c, 0x2, 0x2, 0x79, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x2a, 0x2, 0x2, 0x7b, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x7, 0x2b, 0x2, 0x2, 0x7d, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7f, 0x7, 0x7d, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x81, 0x8, 0x13, 0x2, 0x2, 0x81, 0x28, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x7, 0x7f, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x8, 
    0x14, 0x3, 0x2, 0x85, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x41, 
    0x2, 0x2, 0x87, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x2e, 0x2, 
    0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x8, 0x16, 0x4, 0x2, 
    0x8b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x26, 0x2, 0x2, 0x8d, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x8, 0x17, 0x5, 0x2, 0x8f, 0x90, 
    0x8, 0x17, 0x6, 0x2, 0x90, 0x30, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 
    0x28, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x8, 0x18, 
    0x7, 0x2, 0x94, 0x32, 0x3, 0x2, 0x2, 0x2, 0x95, 0x99, 0x7, 0x24, 0x2, 
    0x2, 0x96, 0x98, 0xb, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x24, 0x2, 0x2, 0x9d, 0x34, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x6, 0x1a, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x68, 
    0x2, 0x2, 0xa0, 0xa1, 0x7, 0x71, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x71, 0x2, 
    0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x6, 0x1a, 0x3, 0x2, 
    0xa4, 0xa5, 0x8, 0x1a, 0x8, 0x2, 0xa5, 0x36, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa7, 0x7, 0x64, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x63, 0x2, 0x2, 0xa8, 0xa9, 
    0x7, 0x74, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x6, 
    0x1b, 0x4, 0x2, 0xab, 0xac, 0x8, 0x1b, 0x9, 0x2, 0xac, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xae, 0x5, 0x35, 0x1a, 0x2, 0xae, 0xb0, 0x5, 0x41, 0x20, 
    0x2, 0xaf, 0xb1, 0x5, 0x37, 0x1b, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb3, 0x5, 0x43, 0x21, 0x2, 0xb3, 0xb4, 0x5, 0x3f, 0x1f, 0x2, 0xb4, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb9, 0x7, 0x25, 0x2, 0x2, 0xb6, 0xb8, 
    0xa, 0x3, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbe, 0x7, 0xf, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc0, 0x7, 0xc, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 
    0x8, 0x1d, 0xa, 0x2, 0xc2, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc5, 0x9, 
    0x4, 0x2, 0x2, 0xc4, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x8, 0x1e, 0xb, 0x2, 
    0xc9, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x44, 0x2, 0x2, 0xcb, 
    0xcc, 0x7, 0x63, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x7c, 0x2, 0x2, 0xcd, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x30, 0x2, 0x2, 0xcf, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x30, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x30, 
    0x2, 0x2, 0xd2, 0x44, 0x3, 0x2, 0x2, 0x2, 0xd, 0x2, 0x3, 0x4, 0x58, 
    0x5f, 0x61, 0x99, 0xb0, 0xb9, 0xbd, 0xc6, 0xc, 0x7, 0x3, 0x2, 0x6, 0x2, 
    0x2, 0x8, 0x2, 0x2, 0x5, 0x2, 0x2, 0x4, 0x3, 0x2, 0x9, 0x3, 0x2, 0x3, 
    0x1a, 0x2, 0x3, 0x1b, 0x3, 0x2, 0x4, 0x2, 0x2, 0x65, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TLexer::Initializer TLexer::_init;
