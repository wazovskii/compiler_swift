#pragma once

#include <memory>
#include <vector>
#include <string>


class String;
class Node;
class Visitor;

class Program final {
public:
    template <class T, class... Args>
    T* create_node(Args&&... args) {
        static_assert(std::is_base_of_v<Node, T>);
        nodes_.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        return dynamic_cast<T*>(nodes_.back().get());
    }
    
    void set_node(Node* node) { node_ = node; }
    Node* get_node() const { return node_; }
    
private:
    std::vector<std::unique_ptr<Node>> nodes_;
    Node* node_ = nullptr;
};

class Node {
public:
    virtual ~Node() = default;
    virtual void accept(Visitor& visitor) = 0;
    void set_type(std::string type) { type_ = type; }
    const std::string& get_type() const { return type_; }
private:
    std::string type_;
};


class Print final : public Node {
public:
    using Object = std::vector<Node*>;
    
    explicit Print(Object object) : object_(std::move(object)) {}
    const Object& object() const { return object_; }
    void accept(Visitor& visitor) override;
    
private:
    Object object_;
};

class Statement final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Statement(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    
};

class Numbes final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Numbes(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    
};

class Opplus final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Opplus(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    std::string token_;
};

class Opminus final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Opminus(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token))  {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
private:
    Elements elements_;
    std::string token_;
    
    
};

class Opmulti final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Opmulti(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
private:
    Elements elements_;
    std::string token_;
};

class Opdivision final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Opdivision(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    std::string token_;
    
};

class Wholeif final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Wholeif(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    
};

class String final : public Node {
public:
    explicit String(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Number final : public Node {
public:
    explicit Number(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class R_float final : public Node {
public:
    explicit R_float(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Importdeclaration final : public Node {
public:
    explicit Importdeclaration(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Variable final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Variable(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
};

class Array final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Array(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
};

class Arithmetic final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Arithmetic(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    std::string token_;
};

class Ifconstrukt final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Ifconstrukt(Elements elements, std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    std::string token_;
    
};

class R_while final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit R_while(Elements elements, std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
    std::string token_;
    
};

class Elseconstrukt final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Elseconstrukt(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
};

class Type final : public Node {
public:
    explicit Type(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Name final : public Node {
public:
    
    explicit Name(std::string text,std::string token) : text_(std::move(text)),token_(std::move(token)) {}
    const std::string& text() const { return text_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
    std::string token_;
    
};

class Funcname final : public Node {
public:
    explicit Funcname(std::string text,std::string token) : text_(std::move(text)),token_(std::move(token)) {}
    const std::string& text() const { return text_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
    std::string token_;
    
};

class Secname final : public Node {
public:
    explicit Secname(std::string text,std::string token) : text_(std::move(text)),token_(std::move(token)) {}
    const std::string& text() const { return text_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
    std::string token_;
    
};

class Comparemembers final : public Node {
public:
    explicit Comparemembers(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Function final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Function(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string token_;
    Elements elements_;
};

class Args final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Args(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
};

class Ret_type final : public Node {
public:
    explicit Ret_type(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Arrayelem final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Arrayelem(Elements elements) : elements_(std::move(elements)) {}
    const Elements& elements() const { return elements_; }
    void accept(Visitor& visitor) override;
    
private:
    Elements elements_;
};

class R_index final : public Node {
public:
    explicit R_index(std::string text) : text_(std::move(text)) {}
    const std::string& text() const { return text_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
};

class Readline final : public Node {
public:
    explicit Readline(std::string text,std::string token) : text_(std::move(text)),token_(std::move(token)) {}
    const std::string& text() const { return text_; }
    const std::string& token() const { return token_; }
    
    void accept(Visitor& visitor) override;
    
private:
    std::string text_;
    std::string token_;
    
};

class Functioncall final : public Node {
public:
    using Elements = std::vector<Node*>;
    
    explicit Functioncall(Elements elements,std::string token) : elements_(std::move(elements)),token_(std::move(token)) {}
    const Elements& elements() const { return elements_; }
    const std::string& token() const { return token_; }
    void accept(Visitor& visitor) override;
    
private:
    std::string token_;
    Elements elements_;
};
