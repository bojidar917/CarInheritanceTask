class CarPart
{
public:
    CarPart();
    CarPart(const char *id, const char *manifacturerName, const char *descrioption);
    CarPart(const CarPart &other);
    CarPart &operator=(const CarPart &other);
    ~CarPart();

    char const *getId() const { return id; }
    char const *getManifacturerName() const { return manifacturerName; }
    char const *getDesctiption() const { return description; }

    void setDesctiption(const char *description);

private:
    char *id;
    char *manifacturerName;
    char *description;

    void destroy();
};
