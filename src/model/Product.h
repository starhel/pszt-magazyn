/**
 * \file   Product.h
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o produkcie.
 */

#ifndef PSZT_PRODUCT_H
#define PSZT_PRODUCT_H

#include <string>

/**
 * \brief Klasa przechowująca informacje o produkcie znajdującym się w magazynie.
 *
 * Kazdy produkt opisany jest przez 3 parametry: nazwę, częstotliwość pobierania w ciągu dnia oraz czas załadunku,
 * gdy produkt znajduje sie na pierwszej półce.
 */
class Product {
public:
    /**
     * Konstruktor klasy Product, który wymaga podania wszystkich parametrów produktu.
     * \param name Nazwa produktu
     * \param frequency Częstotliwość pobierania produktu
     * \param loadingTime Czas załadunku produktu, gdy znajduje się na pierwszej półce
     */
    Product(const std::string &name, double frequency, double loadingTime) : name(name), frequency(frequency),
                                                                           loadingTime(loadingTime)
    {
        number = productCounter++;
    }

    /**
     * \brief Funkcja zwracająca nazwę produktu.
     * \return Obiekt klasy String przechowujący nazwę produktu.
     */
    const std::string& getName() const;

    /**
     * \brief Funkcja zwracająca częstotliwość użycia produktu.
     * \return Liczba zmiennoprzecinkowa - częstotliwość użycia produktu.
     */
    double getFrequency() const;

    /**
     * \brief Funkcja zwracjąca czas załadunku produktu z pierwszej półki.
     * \return Liczba zmiennoprzecinkowa - czas załadunku produktu z pierwszej półki.
     *
     * Zakładamy, że czas pobrania produktu z i-tej półki wynosi i*loadingTime.
     */
    double getLoadingTime() const;

    /**
     * \brief Funkcja zwracająca numer przyporządkowany do produktu.
     * \return Liczba naturalna oznaczająca numer produktu.
     */
    int getNumber() const;

    /**
     * \brief Operator == pozwalajacy na porównanie dwóch produktów
     * \return True, jeżeli produkty są takie same, False w przeciwnym przypadku
     *
     * Dwa produkty są takie same, jeżeli wszystkie ich parametry są takie same.
     */
    bool operator==(const Product& product) const;
    static int productCounter;  /**< Licznik produktów */

private:
    int number;                 /**< Numer porządkowy produktu */
    std::string name;           /**< Nazwa produktu */
    double frequency;           /**< Częstotliwość pobierania produktu */
    double loadingTime;         /**< Czas załadunku produktu, gdy znajduje się na pierwszej półce */
};


#endif //PSZT_PRODUCT_H
