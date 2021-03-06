#pragma once
#include "user.h"
#include <vector>
#include <string>
#include "common.h"
using namespace std;
namespace mmp
{
	class room_def
	{
	public:
		unsigned int m_max_count;
		string m_name;

		room_def();
		~room_def();
	};
    
    class room_info
    {
    public:
        id_type m_id;
        unsigned int m_max_count;
        string m_name;
        string m_owner_name;
        unsigned int m_joined_count;
    };

	class room
	{
		id_type m_id;
		unsigned int m_max_count;
		string m_name;
		unsigned int m_owner_index;
		vector<user> m_participants;
	public:
		room(id_type id, unsigned int max_count,string const& name);
		~room(void);
        
        vector<user> & participants();
        
		const vector<user> & participants() const;

		id_type id() const;

		const string& name() const;

		unsigned int max_count() const;

		const user* owner() const;

		void set_participants_and_owner(vector<user> const& participants,unsigned int owner_idx);
	};
}