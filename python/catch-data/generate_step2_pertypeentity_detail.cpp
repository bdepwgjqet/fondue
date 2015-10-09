#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    //zh-cn
    //char str[41][100] = { "","mso:people.person","mso:event.agent","mso:biology.organism","mso:film.actor","mso:music.track","mso:location.location","mso:film.film","mso:location.dated_location","mso:statistics.population_group","mso:statistics.health_group","mso:statistics.economic_group","mso:statistics.infrastructure_group","mso:statistics.military_group","mso:statistics.housing_group","mso:statistics.government_group","mso:statistics.education_group","mso:statistics.environment_group","mso:location.populated_place","mso:location.city","mso:location.administrative_division","mso:ratings.rated_entity","mso:film.director","mso:travel.destination","mso:people.deceased_person","mso:music.artist","mso:tv.actor","mso:film.writer","mso:media_common.cataloged_instance","mso:music.single","mso:award.nominee"};
    //with localdata
    //char str[41][100] = { "","mso:ratings.rated_entity","mso:local.entity","mso:local.restaurant","mso:event.agent","mso:local.accommodation","mso:people.person","mso:biology.organism","mso:film.actor","mso:location.location","mso:music.track","mso:film.film","mso:location.dated_location","mso:statistics.population_group","mso:statistics.housing_group","mso:location.populated_place","mso:statistics.government_group","mso:statistics.education_group","mso:statistics.military_group","mso:statistics.infrastructure_group","mso:statistics.environment_group","mso:statistics.economic_group","mso:statistics.health_group","mso:location.city","mso:location.administrative_division","mso:travel.destination","mso:film.director","mso:people.deceased_person","mso:music.artist","mso:tv.actor","mso:film.writer","mso:media_common.cataloged_instance","mso:award.nominee"}; 

    //ja-jp
    //char str[41][100] = { "","mso:music.track","mso:music.composition","mso:music.album","mso:event.agent","mso:media_common.creative_work","mso:media_common.cataloged_instance","mso:book.written_work","mso:music.artist","mso:music.single","mso:ratings.rated_entity","mso:book.book","mso:book.edition","mso:people.person","mso:organization.organization","mso:business.operation","mso:media_common.subject","mso:music.record_label","mso:biology.organism","mso:book.author","mso:location.location","mso:film.actor","mso:location.administrative_division" };
    //with localdata
    //char str[41][100] = {"","mso:music.track","mso:music.composition","mso:ratings.rated_entity","mso:local.entity","mso:music.album","mso:event.agent","mso:media_common.creative_work","mso:media_common.cataloged_instance","mso:book.written_work","mso:music.artist","mso:music.single","mso:book.book","mso:book.edition","mso:local.restaurant","mso:people.person","mso:organization.organization","mso:business.operation","mso:media_common.subject","mso:music.record_label","mso:biology.organism","mso:book.author","mso:location.location"};

    //en-us
    char str[41][100] = {"","mso:event.agent","mso:people.person","mso:biology.organism","mso:internet.social_network_user","mso:media_common.cataloged_instance","mso:location.location","mso:architecture.structure","mso:projects.project_focus","mso:location.residential_structure","mso:real_estate.house","mso:ratings.rated_entity","mso:media_common.creative_work","mso:award.ranked_item","mso:book.edition","mso:book.author","mso:music.release_track","mso:book.written_work","mso:organization.organization","mso:business.employer","mso:music.track","mso:education.educational_institution","mso:book.book"};

    puts("//////////////////////////////////////////////////");
    puts("#DECLARE rank string;");
    puts("#DECLARE category string;");
    puts("#DECLARE category_p string;");
    puts("#DECLARE t_n_o_path string;");
    puts("//////////////////////////////////////////////////");
    for (int i = 1; i<41; i++) {
        if (strlen(str[i]) <= 0) {
            break;
        }
        puts("//////////////////////////////////////////////////");
        printf("#SET rank = \"%d\";\n",i);
        printf("#SET category = \"%s\";\n",str[i]);
        str[i][3] = '_';
        printf("#SET category_p = \"%s\";\n",str[i]);
        printf("#SET t_n_o_path = @folder + \"category_name/\"+@rank+\"_\"+@category_p+\".ss\";\n");
        puts("t_n_o = SELECT _SType,");
        puts("       _Name,");
        puts("       _Facet,");
        puts("       _SubjectKey");
        puts("FROM _TNO");
        puts("WHERE _SType == @category;");
        puts("");
        puts("OUTPUT t_n_o");
        puts("TO SSTREAM @t_n_o_path");
        puts("CLUSTERED BY _SubjectKey");
        puts("SORTED BY _Name;");
        puts("//////////////////////////////////////////////////");
        puts("");
    }
    puts("//////////////////////////////////////////////////");
    printf("#SET t_n_o_path = @folder + \"category_name/others.ss\";\n");
    puts("_a = SELECT _SType,");
    puts("       _Name,");
    puts("       _Facet,");
    puts("       _FacetNum,");
    puts("       _SubjectKey");
    puts("FROM _TNO");
    printf("WHERE _SType == \"%s\"",str[1]);
    for (int i=2; i<=20; i++) {
        printf(" OR _SType == \"%s\"",str[i]);
    }
    printf(";\n");
    puts("");
    puts("_b = SELECT _SType,");
    puts("       _Name,");
    puts("       _Facet,");
    puts("       _FacetNum,");
    puts("       _SubjectKey");
    puts("FROM _TNO;");
    puts("");
    puts("t_n_o = SELECT _SType,_Name,_Facet,_FacetNum,_SubjectKey FROM _b LEFT OUTER JOIN _a ON _b._SubjectKey == _a._SubjectKey WHERE _a._SubjectKey == null;");
    puts("");
    puts("OUTPUT t_n_o");
    puts("TO SSTREAM @t_n_o_path");
    puts("CLUSTERED BY _SubjectKey");
    puts("SORTED BY _Name;");
    puts("");
    puts("#DECLARE cnt_o_p string = @folder+\"category_name/\"+\"others-cnt.out\";");
    puts("t_n_o_c = SELECT DISTINCT _SubjectKey,_FacetNum FROM t_n_o;");
    puts("cnt_o = SELECT COUNT(DISTINCT _SubjectKey) AS count,Math.Round(1.0*SUM(t_n_o_c._FacetNum)/COUNT(DISTINCT _SubjectKey)) AS rate FROM t_n_o_c;");
    puts("OUTPUT cnt_o");
    puts("TO @cnt_o_p");
    puts("USING DefaultTextOutputter();");
    puts("//////////////////////////////////////////////////");
    return 0;
}

