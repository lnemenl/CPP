/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenSesame.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:06 by rkhakimu          #+#    #+#             */
/*   Updated: 2025/05/16 11:01:31 by rkhakimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iostream>

class OpenSesame
{
    private:
        std::string filename_;
        std::string from_;
        std::string to_;
        std::ifstream inputfile_;
        std::ofstream outputfile_;
        
    public:
        OpenSesame(std::string filename, std::string from_, std::string to_);
        ~OpenSesame();
};